/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 14:16:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end, 0))
		return ;
	tmp = b->val[b->start] << 32 >> 32;
	b->val[b->start] = (t_ulong)tmp << 32 | b->val[tmp] << 32 >> 32;
	b->val[tmp] = END_OF_STACK << 32 | (t_ulong)b->start;
	b->start = tmp;
}
