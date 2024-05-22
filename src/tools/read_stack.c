/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 13:15:58 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 13:24:53 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	str_isint(char *str)
{
	long	in;
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	in = ft_atol(str);
	if (in < INT_MIN || in > INT_MAX)
		return (0);
	if (ft_strlen(str) > 10)
		return (0);
	return (1);
}

int	does_stack_contain(int *stack, t_uint size, int query)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == query)
			return (1);
		i++;
	}
	return (0);
}

t_uint	*read_stack(char **input, t_uint size)
{
	int *const	stack = malloc(sizeof(int) * size);
	t_uint		*out;
	t_uint		i;
	int			current;

	if (stack == NULL)
		return (NULL);
	i = 0;
	while (input[i] && i < size)
	{
		if (str_isint(input[i]) == 0)
			return (free(stack), NULL);
		current = ft_atoi(input[i]);
		if (does_stack_contain(stack, i, current))
			return (free(stack), NULL);
		stack[i] = current;
		i++;
	}
	if (input[i] || i < size)
		return (free(stack), NULL);
	out = normalize_stack(stack, size);
	free(stack);
	return (out);
}
