/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:21:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 12:48:34 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Does not properly change the value of the 3rd entry.
// S:   1  E: 6  || S:   5  E: 0  
// ////     A    --    B     \\\\
// -_4294967295           2  ||  4294967295  4         _-
// -_         1           3  ||  5           0         _-
// -_         2           6  ||  4           4294967295_-
// -_         3  4294967295  ||  4           4294967295_-
// TOTAL: 7
// sb

// S:   1  E: 6  || S:   4  E: 0  
// ////     A    --    B     \\\\
// -_4294967295           2  ||  4294967295  5         _-
// -_         1           3  ||  4           0         _-
// -_         2           6  ||  4           4294967295_-
// -_         3  4294967295  ||  4           4294967295_-
// TOTAL: 7

void	sb(t_stack *a, t_stack *b)
{
	debug_stacks(a, b);
	ft_printf("%s\n", __func__);
	t_uint	tmp;

	(void)a;
	if (__builtin_expect(b->start == END_OF_STACK || b->start == b->end
		|| (b->val[b->start] & STACK_RIGHT) == b->end, 0))
		return ;
	tmp = b->val[b->start] & STACK_RIGHT;
	b->val[b->start] = (t_ulong)tmp << 32 | (b->val[tmp] & STACK_RIGHT);
	b->val[tmp] = END_OF_STACK << 32 | (t_ulong)b->start;
	b->start = tmp;
}
