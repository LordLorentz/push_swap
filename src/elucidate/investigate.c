/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   investigate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 15:24:56 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:40:12 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "elucidate.h"

t_dpp	chucklenuts(t_uint val, t_uint count, t_uint size, t_mode mode);

static inline t_dpp	sum_stack(
		t_dpp in,
		t_stack *stack,
		t_uint size,
		t_mode mode)
{
	t_uint	current;
	t_dpp	tmp;

	current = stack->start;
	while (current != END_OF_STACK)
	{
		tmp = chucklenuts(current, stack->count, size, mode);
		ft_printf("__--val: %u, dpp: %p\n", current, tmp);
		in += tmp;
		current = stack->val[current] & STACK_RIGHT;
	}
	tmp = chucklenuts(END_OF_STACK, stack->count, size, mode);
	ft_printf("__--val: %u, dpp: %p\n", current, tmp);
	in += tmp;
	return (in);
}

t_dpp	investigate(t_stack *a, t_stack *b, t_uint size)
{
	t_dpp		out;

	out = 0;
	out = sum_stack(out, a, size, A);
	out = sum_stack(out, b, size, B);
	print_stacks(a, b);
	ft_printf("^^^ dpp: %p\n", out);
	return (out);
}
