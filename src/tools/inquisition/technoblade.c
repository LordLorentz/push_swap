/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   technoblade.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 15:01:03 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/09 22:28:47 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//very different behaviour depending on in what stack an item is causes jank
t_dpp	trace(t_stack *stack, t_uint target, t_uint agent, t_mode mode)
{
	t_dpp			out;
	const t_uint	count =stack->count[mode];
	const t_uint	target_offset = stack->val[target].user;
	const t_uint	agent_offset = stack->val[agent].user;

	out = 0;
	if (stack->val[target].container == stack->val[agent].container)
	{
		out += wrap(dif(target_offset, agent_offset), count);
	}
	else
	{
		out += interface(stack, agent);
	}
	return (out);
}

//disapprove distance to neighbour + distance to interface?
//distance to neighbour: dif, then wrap
t_dpp	disapprove(t_stack *stack, t_uint query, t_state state, t_mode mode)
{
	t_dpp	out;

	out = 0;
	if (state == 0)
		return (out);
	out += interface(stack, query);
	if (state & DOWN)
		out += trace(stack, query, neighbour(stack, query, DOWN, mode), mode);
	if (state & UP)
		out += trace(stack, query, neighbour(stack, query, UP, mode), mode);
	return (out);
}

t_dpp	stack_loop(t_stack *stack)
{
	t_dpp	out;
	t_uint	i;
	t_state	state;
	t_mode	mode;

	out = 0;
	i = 0;
	while (i < stack->size)
	{
		state = 0;
		mode = stack->val[i].container;
		if (stack->val[i].prev != neighbour(stack, i, DOWN, mode))
			state |= DOWN;
		if (stack->val[i].next != neighbour(stack, i, UP, mode))
			state |= UP;
		out += disapprove(stack, i, state, mode);
		i += 2;
	}
	return (out);
}

t_dpp	technoblade(t_stack *stack)
{
	t_dpp	out;

	index_stack(stack, A);
	index_stack(stack, B);
	out = 0;
	out += stack_loop(stack);
	out <<= 2;
	out += wrap(stack->head[A], stack->size);
	out += stack->count[B];
	return (out);
}
