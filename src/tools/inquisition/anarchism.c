/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anarchism.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 12:55:33 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/09 13:41:25 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//indexes every value in stack "mode".
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

//finds the amount of moves it takes to get query to the interface.
t_dpp	interface(t_stack *stack, t_uint query)
{
	t_uint	count;
	t_uint	dist;

	count = stack->count[stack->val[query].container];
	dist = stack->val[query].user;
	return (wrap(dist, count));
}

//finds the neighbour of query, in the direction of dir.
t_uint	neighbour(t_stack *stack, t_uint query, t_state dir, t_mode mode)
{
	t_uint	out;

	if (dir == DOWN ^ mode == B)
		out = (query - 1 + stack->size) % stack->size;
	else
		out = (query + 1) % stack->size;
	return (out);
}
