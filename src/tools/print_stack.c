/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 13:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/26 15:42:40 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	print_val(char *format, t_stack *stack, t_uint current, int f)
{
	t_uint	next;
	int		val;

	next = stack->val[current].next;
	if ((current + f < next) ^ (f == -1))
		val = write(1, "\x1b[32m", 5);
	if ((current + f > next) ^ (f == -1))
		val = write(1, "\x1b[31m", 5);
	if ((current + f == next))
		val = write(1, "\x1b[0m", 5);
	ft_printf(format, current);
	val = write(1, "\x1b[0m", 5);
	(void)val;
	return (next);
}

void	print_stacks(t_stack *stack)
{
	t_uint	current_a;
	t_uint	current_b;
	t_uint	i;

	current_a = stack->head[A];
	current_b = stack->head[B];
	i = 0;
	ft_printf("////     A    --    B     \\\\\\\\\n");
	while (i < stack->count[A] || i < stack->count[B])
	{
		if (i < stack->count[A])
			current_a = print_val("-_%8u    |", stack, current_a, 1);
		else
			ft_printf("-_%8c    |", '-');
		if (i < stack->count[B])
			current_b = print_val("|    %-8u_-\n", stack, current_b, -1);
		else
			ft_printf("|    %-8c_-\n", '-');
		i++;
	}
}
