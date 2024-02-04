/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/04 21:49:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end, 0))
		return ;
	tmp = b->val[b->start] << 32 >> 32;
	b->val[b->end] = b->val[b->end] << 32 | (t_ulong)b->start;
	b->val[b->start] = (t_ulong)b->end << 32 | END_OF_STACK;
	b->end = b->start;
	b->start = tmp;
	b->val[b->start] |= END_OF_STACK << 32;
}
