/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 15:07:47 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	const t_uint	size = argc - 1;
	t_uint			*temp;
	t_stack			*stack;
	t_uint			out;

	if (argc < 2)
		exit_wrapper();
	if (argc < 3)
		return (0);
	temp = read_stack(argv + 1, size);
	if (temp == NULL)
		exit_wrapper();
	stack = curse_stack(temp, size);
	free(temp);
	out = 0;
	print_stacks(stack);
	scuttle_dsc(stack, DSC_EMPTY, 0xE);
	print_stacks(stack);
	scuttle_dsc(stack, 0xE, DSC_EMPTY);
	print_stacks(stack);
	scuttle_dsc(stack, DSC_EMPTY, 0xA2);
	print_stacks(stack);
	scuttle_dsc(stack, 0xA2, DSC_EMPTY);
	print_stacks(stack);
	// print_rifle(stack, 2);
	free_stack(stack);
	return (out);
}
