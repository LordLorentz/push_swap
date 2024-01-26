/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   curse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 15:01:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/26 15:58:11 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	*curse_stack(t_uint *stack, t_uint size, t_uint *start)
{
	t_uint *const	out = malloc(sizeof(t_uint) * size);
	t_uint			i;

	ft_printf("__-|size - 1 = %u\n", size - 1);
	*start = stack[0];
	i = 0;
	while (i < size - 1)
	{
		out[stack[i]] = stack[i + 1];
		i++;
	}
	out[stack[i]] = END_OF_STACK;
	free(stack);
	return (out);
}
