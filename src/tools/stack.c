/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/19 13:57:31 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/19 14:00:23 by mmosk         ########   odam.nl         */
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

void	free_stack(t_stack *stack)
{
	free(stack->val);
	free(stack);
}
