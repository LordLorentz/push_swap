/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/18 13:03:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_uint size)
{
	t_stack	*out;

	out = malloc(sizeof(t_stack));
	if (out == NULL)
		return (NULL);
	out->val = malloc(size * sizeof(t_item));
	if (out->val == NULL)
		return (free(out), NULL);
	return (out);
}

t_stack	*clone_stack(t_uint size, t_stack *src)
{
	t_stack	*out;

	out = create_stack(size);
	if (out == NULL)
		return (NULL);
	out->head[A] = src->head[A];
	out->tail[A] = src->tail[A];
	out->count[A] = src->count[A];
	out->head[B] = src->head[B];
	out->tail[B] = src->tail[B];
	out->count[B] = src->count[B];
	ft_memcpy(out->val, src->val, size * sizeof(t_item));
	return (out);
}

t_stack	*copy_stack(t_stack *dst, t_stack *src, t_uint size)
{
	dst->head[A] = src->head[A];
	dst->tail[A] = src->tail[A];
	dst->count[A] = src->count[A];
	dst->head[B] = src->head[B];
	dst->tail[B] = src->tail[B];
	dst->count[B] = src->count[B];
	ft_memcpy(dst->val, src->val, size * sizeof(t_item));
	return (dst);
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
	out->head[B] = END_OF_STACK;
	out->tail[B] = END_OF_STACK;
	out->count[B] = 0;
	out->val[stack[0]].prev = END_OF_STACK;
	out->val[stack[0]].next = stack[1];
	i = 1;
	while (i < size - 1)
	{
		out->val[stack[i]].prev = stack[i - 1];
		out->val[stack[i]].prev = stack[i + 1];
		i++;
	}
	out->val[stack[i]].prev = stack[i - 1];
	out->val[stack[i]].prev = END_OF_STACK;
	return (out);
}

void	free_stack(t_stack *stack)
{
	free(stack->val);
	free(stack);
}
