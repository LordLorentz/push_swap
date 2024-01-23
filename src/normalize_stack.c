/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:35:03 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/23 22:33:53 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//O(n) = n^2

inline unsigned int	stack_highest_index(int *stack, unsigned int size)
{
	unsigned int	i;
	int				highest;
	unsigned int	highest_index;

	i = 0;
	highest = INT_MIN;
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

inline unsigned int	stack_lowest_index(int *stack, unsigned int size)
{
	unsigned int	i;
	int				lowest;
	unsigned int	lowest_index;

	i = 0;
	lowest = INT_MAX;
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

unsigned int	*normalize_stack(int *stack, unsigned int size)
{
	unsigned int *const	out = malloc(sizeof(unsigned int) * size);
	int					lowest;
	unsigned int		i;
	unsigned int		j;
	unsigned int		target;

	if (out == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		lowest = INT_MAX;
		j = 0;
		while (j < size)
		{
			if (stack[j] < lowest)
			{
				target = j;
				lowest = stack[j];
			}
			j++;
		}
		stack[target] = INT_MAX;
		out[target] = i;
		i++;
	}
	return (free(stack), out);
}
