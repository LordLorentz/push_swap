/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anarchism.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 12:55:33 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/06 15:11:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//indexes every value
void	index_stack(t_stack *stack, t_mode mode)
{
	t_uint	count;
	t_uint	current;
	t_uint	i;

	count = stack->count[mode];
	current = stack->head[mode];
	i = 0;
	while (i < count)
	{
		stack->val[current].user = i;
		current = stack->val[current].next;
		i++;
	}
}
