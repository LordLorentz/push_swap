/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 15:40:34 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
		return (1);
	tmp = a->val[a->start] & STACK_RIGHT;
	a->val[a->end] = (a->val[a->end] & STACK_LEFT) | (t_ulong)a->start;
	a->val[a->start] = (t_ulong)a->end << 32 | END_OF_STACK;
	a->end = a->start;
	a->start = tmp;
	a->val[a->start] |= END_OF_STACK << 32;
	return (0);
}
