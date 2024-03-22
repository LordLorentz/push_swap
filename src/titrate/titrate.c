/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   titrate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/22 15:06:21 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

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
	if (rifle_titrate(a, b, 2, result))
		return (1);
	free_stack(a);
	free_stack(b);
	if (interpret_result(result) == 1)
		return (free_hashlist_arr(result, RESULT_SIZE), 1);
	free_hashlist_arr(result, RESULT_SIZE);
	return (0);
}
