/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/08 17:50:15 by mmosk         ########   odam.nl         */
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
	t_uint			out;

	if (argc < 2)
		exit_wrapper();
	if (argc < 3)
		return (0);
	temp = read_stack(argv + 1, size);
	if (temp == NULL)
		exit_wrapper();
	a = curse_stack(temp, size);
	b = create_stack(size, END_OF_STACK, END_OF_STACK, 0);
	free(temp);
	out = convene(a, b, size);
	free_stack(a);
	free_stack(b);
	return (out);
}
