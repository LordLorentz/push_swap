/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   technoblade.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 15:01:03 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/06 15:41:01 by mmosk         ########   odam.nl         */
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

// //three yards of poison. run for your life.
// //too late.
// t_dpp	concatenate(t_stack *stack, t_uint current, t_uint i, bool up)
// {
// 	t_uint	count;
// 	t_uint	query;
// 	t_dpp	out;

// 	count = stack->count[stack->val[current].container];
// 	if (up == true)
// 		query = (current + 1) % stack->size;
// 	else
// 		query = (current - 1) % stack->size;
// 	out = 0;
// 	out += interface(stack, query);
// 	out += wrap(i, count);
// 	return (out);
// }

// //split into hardcoded A and B?
// //don't need to track i any longer.
// //'cept for the loop.
// t_dpp	stack_loop(t_stack *stack, t_mode mode)
// {
// 	t_uint	current;
// 	t_dpp	out;
// 	t_uint	i;

// 	current = stack->head[mode];
// 	out = 0;
// 	i = 0;
// 	while (i < stack->count[mode])
// 	{
// 		if (dif(stack->val[current].prev, current) != 1//wrap this, somehow
// 			&& (stack->val[current].prev < current) ^ (mode == A))
// 			out += concatenate(stack, current, i, (mode == A) ^ true);
// 		if (dif(stack->val[current].next, current) != 1
// 			&& (stack->val[current].next > current) ^ (mode == A))
// 			out += concatenate(stack, current, i, (mode == A) ^ false);
// 		current = stack->val[current].next;
// 		i++;
// 	}
// 	return (out);
// }

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
