/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/14 22:05:22 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_uint size, t_uint start, t_uint end, t_uint count)
{
	t_stack	*out;

	out = malloc(sizeof(t_stack));
	if (out == NULL)
		return (NULL);
	out->val = malloc(size * sizeof(t_ulong));
	if (out->val == NULL)
		return (free(out), NULL);
	out->start = start;
	out->end = end;
	out->count = count;
	return (out);
}

t_stack	*copy_stack(t_uint size, t_stack *stack)
{
	t_stack	*out;

	out = create_stack(size, stack->start, stack->end, stack->count);
	if (out == NULL)
		return (NULL);
	ft_memcpy(out->val, stack->val, size * sizeof(t_ulong));
	return (out);
}

t_stack	*curse_stack(t_uint *stack, t_uint size)
{
	t_stack	*out;
	t_uint	i;

	out = create_stack(size, stack[0], stack[size - 1], size);
	if (out == NULL)
		return (NULL);
	out->val[stack[0]] = END_OF_STACK << 32 | (t_ulong)stack[1];
	i = 1;
	while (i < size - 1)
	{
		out->val[stack[i]] = (t_ulong)stack[i -1] << 32 | (t_ulong)stack[i + 1];
		i++;
	}
	out->val[stack[i]] = (t_ulong)stack[i -1] << 32 | END_OF_STACK;
	return (out);
}

void	free_stack(t_stack *stack)
{
	free(stack->val);
	free(stack);
}
