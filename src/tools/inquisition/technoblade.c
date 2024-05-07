/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   technoblade.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 15:01:03 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/07 13:41:43 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//finds the amount of moves it takes to get query to the interface.
t_dpp	interface(t_stack *stack, t_uint query)
{
	t_uint	count;
	t_uint	dist;

	count = stack->count[stack->val[query].container];
	dist = stack->val[query].user;
	return (wrap(dist, count));
}

t_uint	neighbour(t_stack *stack, t_uint query, t_dir dir, t_mode mode)
{
	t_uint	out;

	if (dir == DOWN ^ mode == B)
		out = (query - 1 + stack->size) % stack->size;
	else
		out = (query + 1) % stack->size;
	return (out);
}

//disapprove distance to neighbour + distance to interface?
//distance to neighbour: dif, then wrap
t_dpp	disapprove(t_stack *stack, t_uint query, t_dir dir, t_mode mode)
{
	t_dpp	out;

	out = 0;
	out += interface(stack, query);
	out += interface(stack, neighbour(stack, query, dir, mode));
	return (out);
}

t_dpp	stack_loop(t_stack *stack, t_mode mode)
{
	t_uint	current;
	t_dpp	out;
	t_uint	i;

	current = stack->head[mode];
	out = 0;
	i = 0;
	while (i < stack->count[mode])
	{
		if (stack->val[current].prev != neighbour(stack, current, DOWN, mode))
			out += disapprove(stack, current, DOWN, mode);
		if (stack->val[current].next != neighbour(stack, current, UP, mode))
			out += disapprove(stack, current, UP, mode);
		current = stack->val[current].next;
		i++;
	}
	return (out);
}

t_dpp	technoblade(t_stack *stack)
{
	t_dpp	out;

	index_stack(stack, A);
	index_stack(stack, B);
	out = 0;
	out += wrap(stack->head[A], stack->size);
	out += stack->count[B];
	out += stack_loop(stack, A);
	out += stack_loop(stack, B);
	return (out);
}
