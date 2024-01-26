/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/26 15:57:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	const t_uint	size = argc - 1;
	t_uint			start;
	t_uint			*stack;
	t_uint			i;

	stack = read_stack(argv + 1, size);
	if (stack == NULL || argc < 2)
		ft_exit();
	i = 0;
	while (i < size)
	{
		ft_printf("%u\n", stack[i]);
		i++;
	}
	stack = curse_stack(stack, size, &start);
	if (stack == NULL)
		ft_exit();
	ft_printf("------\n");
	i = 0;
	while (i < size)
	{
		ft_printf("%u\n", stack[i]);
		i++;
	}
	exit(0);
}
