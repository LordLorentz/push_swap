/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 11:46:21 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	debug_stacks(a, b);
	ft_printf("%s\n", __func__);
	if (__builtin_expect(a->start == END_OF_STACK, 0))
		return ;
	if (__builtin_expect(b->start != END_OF_STACK, 0))
		b->val[b->start]
			= (t_ulong)a->start << 32 | (b->val[b->start] & STACK_RIGHT);
	else
		b->end = a->start;
	b->val[a->start] = END_OF_STACK << 32 | (t_ulong)b->start;
	b->start = a->start;
	a->start = a->val[a->start] & STACK_RIGHT;
	if (__builtin_expect(a->start != END_OF_STACK, 0))
		a->val[a->start] |= END_OF_STACK << 32;
}
