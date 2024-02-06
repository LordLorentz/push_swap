/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 11:44:52 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *a, t_stack *b)
{
	debug_stacks(a, b);
	ft_printf("%s\n", __func__);
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end, 0))
		return ;
	tmp = b->val[b->start] & STACK_RIGHT;
	b->val[b->end] = (b->val[b->end] & STACK_LEFT) | (t_ulong)b->start;
	b->val[b->start] = (t_ulong)b->end << 32 | END_OF_STACK;
	b->end = b->start;
	b->start = tmp;
	b->val[b->start] |= END_OF_STACK << 32;
}
