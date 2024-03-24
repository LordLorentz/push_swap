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

int	manage_test(t_stack *a, t_stack *b);

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

	a = fill_stack(STACK_SIZE, 0, (STACK_SIZE / 2) - 1);
	if (a == NULL)
		return (1);
	b = fill_stack(STACK_SIZE, STACK_SIZE / 2, STACK_SIZE - 1);
	if (b == NULL)
		return (free_stack(a), 1);
	
	
	free_stack(a);
	free_stack(b);
	
	return (0);
}

int	manage_test(t_stack *a, t_stack *b)
{
	t_hashlist	**control;
	t_hashlist	**test;
	
	control = malloc(RESULT_SIZE * sizeof(t_hashlist *));
	if (control == NULL)
		return (1);
	ft_memset(control, 0, RESULT_SIZE * sizeof(t_hashlist *));
	if (control_rifle(a, b, TITRATE_DEPTH, control))
		return (1);
	if (interpret_result(result) == 1)
		return (free_hashlist_arr(result, RESULT_SIZE), 1);
	free_hashlist_arr(result, RESULT_SIZE);
}
