/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:27:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 15:42:19 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
		return (1);
	tmp = a->val[a->end] >> 32;
	a->val[a->start] = (t_ulong)a->end << 32 | (a->val[a->start] & STACK_RIGHT);
	a->val[a->end] = END_OF_STACK << 32 | (t_ulong)a->start;
	a->start = a->end;
	a->end = tmp;
	a->val[a->end] |= END_OF_STACK;
	return (0);
}
