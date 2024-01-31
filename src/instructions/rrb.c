/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 14:17:16 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end, 0))
		return ;
	tmp = b->val[b->end] >> 32;
	b->val[b->start] = (t_ulong)b->end << 32 | b->val[b->start] << 32 >> 32;
	b->val[b->end] = END_OF_STACK << 32 | (t_ulong)b->start;
	b->start = b->end;
	b->end = tmp;
	b->val[b->end] |= END_OF_STACK;
}
