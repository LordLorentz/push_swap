/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 14:17:16 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
		return ;
	tmp = a->val[a->start] << 32 >> 32;
	a->val[a->end] = a->val[a->end] << 32 | (t_ulong)a->start;
	a->val[a->start] = (t_ulong)a->end << 32 | END_OF_STACK;
	a->end = a->start;
	a->start = tmp;
	a->val[a->start] |= END_OF_STACK << 32;
}
