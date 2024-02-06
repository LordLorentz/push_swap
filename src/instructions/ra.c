/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 11:44:52 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	debug_stacks(a, b);
	ft_printf("%s\n", __func__);
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
		return ;
	tmp = a->val[a->start] & STACK_RIGHT;
	a->val[a->end] = (a->val[a->end] & STACK_LEFT) | (t_ulong)a->start;
	a->val[a->start] = (t_ulong)a->end << 32 | END_OF_STACK;
	a->end = a->start;
	a->start = tmp;
	a->val[a->start] |= END_OF_STACK << 32;
}
