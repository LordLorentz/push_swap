/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/19 13:57:31 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/06 14:40:23 by mmosk         ########   odam.nl         */
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
	out->size = size;
	return (out);
}

//size is assumed to be equal.
t_stack	*copy_stack(t_stack *dst, t_stack *src)
{
	dst->head[A] = src->head[A];
	dst->tail[A] = src->tail[A];
	dst->count[A] = src->count[A];
	dst->head[B] = src->head[B];
	dst->tail[B] = src->tail[B];
	dst->count[B] = src->count[B];
	ft_memcpy(dst->val, src->val, src->size * sizeof(t_item));
	return (dst);
}

t_stack	*clone_stack(t_stack *src)
{
	t_stack	*out;

	out = create_stack(src->size);
	if (out == NULL)
		return (NULL);
	copy_stack(out, src);
	return (out);
}

void	free_stack(t_stack *stack)
{
	free(stack->val);
	free(stack);
}
