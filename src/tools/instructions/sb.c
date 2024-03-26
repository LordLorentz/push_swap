/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/25 22:21:29 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end
			|| (b->val[b->start] & STACK_RIGHT) == b->end, 0))
		return (1);
	tmp = b->val[b->start] & STACK_RIGHT;
	b->val[b->val[tmp] & STACK_RIGHT] = (t_ulong)b->start << 32
		| (b->val[b->val[tmp] & STACK_RIGHT] & STACK_RIGHT);
	b->val[b->start] = (t_ulong)tmp << 32 | (b->val[tmp] & STACK_RIGHT);
	b->val[tmp] = END_OF_STACK << 32 | (t_ulong)b->start;
	b->start = tmp;
	return (0);
}
