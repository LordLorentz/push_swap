/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 12:48:19 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	debug_stacks(a, b);
	ft_printf("%s\n", __func__);
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end
		|| (a->val[a->start] & STACK_RIGHT) == a->end, 0))
		return ;
	tmp = a->val[a->start] & STACK_RIGHT;
	a->val[a->start] = (t_ulong)tmp << 32 | (a->val[tmp] & STACK_RIGHT);
	a->val[tmp] = END_OF_STACK << 32 | (t_ulong)a->start;
	a->start = tmp;
}

// void	std_sa(t_stack *a, t_stack *b)
// {
// 	t_uint	tmp;

// 	(void)b;
// 	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
// 		return ;
// 	if (__builtin_expect(a->val[a->start] & STACK_RIGHT == a->end, 0))
// 		return (ra(a, b), 0);
// 	tmp = a->val[a->start] & STACK_RIGHT;
// 	a->val[a->start] = (t_ulong)tmp << 32 | (a->val[tmp] & STACK_RIGHT);
// 	a->val[tmp] = END_OF_STACK << 32 | (t_ulong)a->start;
// 	a->start = tmp;
// }
