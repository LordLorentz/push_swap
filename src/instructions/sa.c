/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 14:16:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	t_uint	tmp;

	(void)b;
	if (__builtin_expect(a->start == END_OF_STACK || a->start == a->end, 0))
		return ;
	tmp = a->val[a->start] << 32 >> 32;
	a->val[a->start] = (t_ulong)tmp << 32 | a->val[tmp] << 32 >> 32;
	a->val[tmp] = END_OF_STACK << 32 | (t_ulong)a->start;
	a->start = tmp;
}
