/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:00:42 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	set_container(t_stack *stack, t_uint size)
{
	t_uint i;

	i = 0;
	while (i < size)
	{
		stack->val[i].container = A;
		i++;
	}
}

t_stack	*curse_stack(t_uint *stack, t_uint size)
{
	t_stack	*out;
	t_uint	i;

	out = create_stack(size);
	if (out == NULL)
		return (NULL);
	out->head[A] = stack[0];
	out->tail[A] = stack[size - 1];
	out->count[A] = size;
	set_container(out, size);
	out->head[B] = END_OF_STACK;
	out->tail[B] = END_OF_STACK;
	out->count[B] = 0;
	out->val[stack[0]].prev = END_OF_STACK;
	out->val[stack[0]].next = stack[1];
	i = 1;
	while (i < size - 1)
	{
		out->val[stack[i]].prev = stack[i - 1];
		out->val[stack[i]].next = stack[i + 1];
		i++;
	}
	out->val[stack[i]].prev = stack[i - 1];
	out->val[stack[i]].next = END_OF_STACK;
	return (out);
}
