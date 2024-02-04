/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/04 21:49:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (__builtin_expect(b->start == END_OF_STACK, 0))
		return ;
	if (__builtin_expect(a->start != END_OF_STACK, 0))
		a->val[a->start]
			= (t_ulong)b->start << 32 | a->val[a->start] << 32 >> 32;
	else
		a->end = b->start;
	a->val[b->start] = END_OF_STACK << 32 | (t_ulong)a->start;
	a->start = b->start;
	b->start = b->val[b->start] << 32 >> 32;
	if (__builtin_expect(b->start != END_OF_STACK, 0))
		b->val[b->start] |= END_OF_STACK << 32;
}
