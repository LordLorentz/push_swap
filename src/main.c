/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/11 18:39:59 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static inline void	test_scuttle(t_stack *a, t_stack *b)
// {
// 	const t_ulong	prev = 0xee;
// 	const t_ulong	next = 0xe2;

// 	print_stacks(a, b);
// 	scuttle_dsc(a, b, 0, prev);
// 	print_stacks(a, b);
// 	scuttle_dsc(a, b, prev, next);
// 	print_stacks(a, b);
// 	scuttle_dsc(a, b, next, 0);
// 	print_stacks(a, b);
// }

int	main(int argc, char **argv)
{
	const t_uint	size = argc - 1;
	t_uint			*temp;
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		exit_wrapper();
	temp = read_stack(argv + 1, size);
	if (temp == NULL)
		exit_wrapper();
	a = curse_stack(temp, size);
	b = create_stack(size, END_OF_STACK, END_OF_STACK, 0);
	free(temp);
	agent_sort(a, b, size, MAX_DEPTH);
	free_stack(a);
	free_stack(b);
	return (0);
}
