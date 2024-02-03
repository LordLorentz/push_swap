/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:35:03 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/29 22:22:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline t_uint	stack_highest_index(int *stack, t_uint size)
{
	t_uint	i;
	int		highest;
	t_uint	highest_index;

	i = 0;
	highest = INT_MIN;
	highest_index = 0;
	while (i < size)
	{
		if (stack[i] > highest)
		{
			highest_index = i;
			highest = stack[i];
		}
		i++;
	}
	return (highest_index);
}

static inline t_uint	stack_lowest_index(int *stack, t_uint size)
{
	t_uint	i;
	int		lowest;
	t_uint	lowest_index;

	i = 0;
	lowest = INT_MAX;
	lowest_index = 0;
	while (i < size)
	{
		if (stack[i] < lowest)
		{
			lowest_index = i;
			lowest = stack[i];
		}
		i++;
	}
	return (lowest_index);
}

//O(n) = n^2
//Normalizes a stack while preserving the order of its contents.
t_uint	*normalize_stack(int *stack, t_uint size)
{
	t_uint *const	out = malloc(sizeof(t_uint) * size);
	t_uint			highest;
	t_uint			i;
	t_uint			target;

	if (out == NULL)
		ft_exit();
	highest = stack_highest_index(stack, size);
	out[highest] = INT_MAX;
	i = 0;
	while (i < size - 1)
	{
		target = stack_lowest_index(stack, size);
		stack[target] = INT_MAX;
		out[target] = i;
		i++;
	}
	out[highest] = i;
	free(stack);
	return (out);
}
