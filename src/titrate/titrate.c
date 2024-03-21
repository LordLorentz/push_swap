/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   titrate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/21 21:01:55 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "hashlist.h"

t_ulong	hash_stacks(t_stack *a, t_stack *b);
t_dsc	inc_dsc(t_dsc discriminant);
int 	interpret_result(t_hashlist **result);

//horrible sane array mixed with my evil
t_stack	*fill_stack(t_uint size, t_ulong start, t_ulong end)
{
	t_stack *stack;
	t_ulong	i;

	stack = create_stack(size, start, end, (end - start) + 1);
	if (stack == NULL)
		return (NULL);
	stack->val[start] = (END_OF_STACK << 32UL) | (start + 1);
	i = start + 1;
	while (i < end)
	{
		stack->val[i] = ((i - 1) << 32) | (i + 1); 
		i++;
	}
	stack->val[end] = ((end - 1) << 32UL) | END_OF_STACK;
	return (stack);
}

int	run_titrate(t_stack *a, t_stack *b, t_dsc start, t_hashlist **result)
{
	t_dsc	current_dsc;
	t_dsc	prev_dsc;
	t_ulong	hash;
	t_uint	i;

	i = 1;
	while (scuttle_dsc(a, b, DSC_EMPTY, start))
		start = iter_dsc(start);
	hash = hash_stacks(a, b);
	if (insert_hash(&result[hash % RESULT_SIZE], hash))
		return (1);
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		i++;
		while (scuttle_dsc(a, b, prev_dsc, current_dsc))//dangerous
			current_dsc = iter_dsc(current_dsc);
		hash = hash_stacks(a, b);
		if (insert_hash(&result[hash % RESULT_SIZE], hash))
			return (1);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, prev_dsc, DSC_EMPTY);
	return (0);
}

int	rifle_titrate(t_stack *a, t_stack *b, t_uint depth, t_hashlist **result)
{
	t_uint	size;

	size = 1;
	while (size <= depth)
	{
		if (run_titrate(a, b, mk_dsc(size), result))
		{
			free_hashlist_arr(result, RESULT_SIZE);
			free_stack(a);
			free_stack(b);
			return (1);
		}
		size++;
	}
	return (0);
}

int main(void)
{
	t_stack		*a;
	t_stack		*b;
	t_hashlist	**result;

	a = fill_stack(16, 0, 7);
	if (a == NULL)
		return (1);
	b = fill_stack(16, 8, 15);
	if (b == NULL)
		return (free_stack(a), 1);
	result = malloc(RESULT_SIZE * sizeof(t_hashlist *));
	ft_memset(result, 0, RESULT_SIZE * sizeof(t_hashlist *));
	if (result == NULL)
		return (free_stack(a), free_stack(b), 1);
	if (rifle_titrate(a, b, 3, result))
		return (1);
	free_stack(a);
	free_stack(b);
	if (interpret_result(result) == 1)
		return (free_hashlist_arr(result, RESULT_SIZE), 1);
	free_hashlist_arr(result, RESULT_SIZE);
	return (0);
}
