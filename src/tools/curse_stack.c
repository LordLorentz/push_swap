/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 15:02:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	out->head[B] = END_OF_STACK;
	out->tail[B] = END_OF_STACK;
	out->count[B] = 0;
	i = 0;
	while (i < size)
	{
		out->val[stack[i]].prev = stack[(i + size - 1) % size];
		out->val[stack[i]].next = stack[(i + 1) % size];
		out->val[stack[i]].container = A;
		i++;
	}
	return (out);
}
