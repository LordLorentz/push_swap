/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 12:41:34 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/20 13:46:24 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint get_depth(t_uint size)
{
	t_uint	depth;
	t_uint	i;

	i = 0U;
	depth = 0U;
	while (i < 32U)
	{
		if (size & 1U << i)
			depth = i;
		i++;
	}
	return (depth);
}

int	execute(t_stack *stack, t_inum instruction)
{
	scuttle_dsc(stack, DSC_EMPTY, instruction);
	return (print_dsc(instruction));
}

int	radix_sort(t_stack *stack)
{
	t_uint	depth = get_depth(stack->size);
	t_uint	i;
	t_uint	j;
	int		out;

	i = 0;
	while (i <= depth)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->head[A] & 1 << i)
				out = execute(stack, _RA);
			else
				out = execute(stack, _PB);
			if (out)
				return (1);
			j++;
		}
		while (stack->count[B] != 0)
			if (execute(stack, _PA))
				return (1);
		i++;
	}
	return (0);
}
