/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/12 14:29:19 by mmosk         ########   odam.nl         */
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
		ft_exit();
	temp = read_stack(argv + 1, size);
	a = curse_stack(temp, size);
	b = create_stack(size, END_OF_STACK, END_OF_STACK, 0);
	agent_sort(a, b, size, MAX_DEPTH);
	free(a->val);
	free(b->val);
	free(a);
	free(b);
	exit(0);
}
