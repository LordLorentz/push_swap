/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 15:42:00 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end, 0))
		return (1);
	tmp = b->val[b->start] & STACK_RIGHT;
	b->val[b->end] = (b->val[b->end] & STACK_LEFT) | (t_ulong)b->start;
	b->val[b->start] = (t_ulong)b->end << 32 | END_OF_STACK;
	b->end = b->start;
	b->start = tmp;
	b->val[b->start] |= END_OF_STACK << 32;
	return (0);
}
