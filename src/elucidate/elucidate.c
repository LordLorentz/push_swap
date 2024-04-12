/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elucidate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 15:50:46 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "elucidate.h"

int	manage_test(t_stack *a, t_stack *b);

t_stack	*fill_stack(t_uint size, t_ulong start, t_ulong end)
{
	t_stack	*stack;
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

int	main(void)
{
	t_stack		*a;
	t_stack		*b;
	int			out;

	a = fill_stack(STACK_SIZE, 0, STACK_SIZE - 1);
	if (a == NULL)
		return (1);
	b = create_stack(STACK_SIZE, END_OF_STACK, END_OF_STACK, 0);
	if (b == NULL)
		return (free_stack(a), 1);
	out = manage_test(a, b);
	free_stack(a);
	free_stack(b);
	return (out);
}

int	manage_test(t_stack *a, t_stack *b)
{
	t_dpplist	**test;
	int			out;

	test = malloc(RESULT_SIZE * sizeof(t_dpplist *));
	if (test == NULL)
		return (1);
	ft_memset(test, 0, RESULT_SIZE * sizeof(t_dpplist *));
	out = test_rifle(a, b, TITRATE_DEPTH, test);
	if (out == 0)
		out = interpret_result(test);
	free_dpplist_arr(test, RESULT_SIZE);
	return (out);
}
