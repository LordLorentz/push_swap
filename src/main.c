/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/05 12:40:41 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	print_stacks(t_stack *a, t_stack *b)
{
	unsigned int	current_a;
	unsigned int	current_b;

	current_a = a->start;
	current_b = b->start;
	ft_printf("\n////     A    --    B     \\\\\\\\\n");
	while (current_a != END_OF_STACK || current_b != END_OF_STACK)
	{
		if (current_a != END_OF_STACK)
		{
			ft_printf("-_%8u    |", current_a);
			current_a = a->val[current_a] << 32 >> 32;
		}
		else
			ft_printf("-_%8c    |", '-');
		if (current_b != END_OF_STACK)
		{
			ft_printf("|    %-8u_-\n", current_b);
			current_b = b->val[current_b] << 32 >> 32;
		}
		else
			ft_printf("|    %-8c_-\n", '-');
	}
}

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
	t_ulong			current_dsc;

	if (argc < 2)
		ft_exit();
	temp = read_stack(argv + 1, size);
	a = curse_stack(temp, size);
	b = create_stack(size, END_OF_STACK, END_OF_STACK);
	print_stacks(a, b);
	current_dsc = run_cycle(a, b, DSC_START, size);
	ft_printf("Discriminant: %p\n", current_dsc);
	print_stacks(a, b);
	exit(0);
}
