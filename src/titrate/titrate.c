/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   titrate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 12:07:10 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

int	manage_test(t_stack *stack);

t_stack	*fill_stack(void)
{
	t_stack	*stack;
	t_uint	temp[STACK_SIZE];
	t_uint	i;

	i = 0;
	while (i < STACK_SIZE)
	{
		temp[i] = i;
		i++;
	}
	stack = curse_stack(temp, STACK_SIZE);
	return (stack);
}

int	main(void)
{
	t_stack		*stack;
	int			out;

	stack = fill_stack();
	if (stack == NULL)
		return (1);
	scuttle_dsc(stack, DSC_EMPTY, 0xEEEEEEEEEEEEEEEE);
	out = manage_test(stack);
	free_stack(stack);
	return (out);
}

int	manage_test(t_stack *stack)
{
	t_hashlist	**control;
	t_hashlist	**test;
	int			out;

	control = malloc(RESULT_SIZE * sizeof(t_hashlist *));
	if (control == NULL)
		return (1);
	test = malloc(RESULT_SIZE * sizeof(t_hashlist *));
	if (test == NULL)
		return (free(control), 1);
	ft_memset(control, 0, RESULT_SIZE * sizeof(t_hashlist *));
	ft_memset(test, 0, RESULT_SIZE * sizeof(t_hashlist *));
	if (control_rifle(stack, TITRATE_DEPTH, control))
		return (free_hashlist_arr(control, RESULT_SIZE), free(test), 1);
	out = test_rifle(stack, TITRATE_DEPTH, test);
	if (out == 0)
		out = interpret_result(control, test);
	free_hashlist_arr(control, RESULT_SIZE);
	free_hashlist_arr(test, RESULT_SIZE);
	return (out);
}
