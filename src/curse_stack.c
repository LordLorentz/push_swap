/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/09 12:22:39 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_uint size, t_uint start, t_uint end, t_uint count)
{
	t_stack	*out;

	out = malloc(sizeof(t_stack));
	if (out == NULL)
		ft_exit();
	out->val = malloc(sizeof(t_ulong) * size);
	if (out->val == NULL)
		ft_exit();
	out->start = start;
	out->end = end;
	out->count = count;
	return (out);
}

t_stack	*curse_stack(t_uint *stack, t_uint size)
{
	t_stack	*out;
	t_uint	i;

	out = create_stack(size, stack[0], stack[size - 1], size);
	out->val[stack[0]] = END_OF_STACK << 32 | (t_ulong)stack[1];
	i = 1;
	while (i < size - 1)
	{
		out->val[stack[i]] = (t_ulong)stack[i -1] << 32 | (t_ulong)stack[i + 1];
		i++;
	}
	out->val[stack[i]] = (t_ulong)stack[i -1] << 32 | END_OF_STACK;
	free(stack);
	return (out);
}
