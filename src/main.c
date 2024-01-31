/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 13:34:01 by mmosk         ########   odam.nl         */
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

int	main(int argc, char **argv)
{
	const t_uint	size = argc - 1;
	t_uint			*temp;
	t_stack			*a;
	t_stack			*b;
	t_uint			i;

	if (argc < 2)
		ft_exit();
	temp = read_stack(argv + 1, size);
	i = 0;
	while (i < size)
	{
		ft_printf("%u\n", temp[i]);
		i++;
	}
	a = curse_stack(temp, size);
	b = create_stack(size, END_OF_STACK, END_OF_STACK);
	print_stacks(a, b);
	rrb(a, b);
	sb(a, b);
	pa(a, b);
	pb(a, b);
	print_stacks(a, b);
	rb(a, b);
	rrb(a, b);
	sb(a, b);
	pb(a, b);
	rrb(a, b);
	print_stacks(a, b);
	pb(a, b);
	pb(a, b);
	sb(a, b);
	print_stacks(a, b);
	exit(0);
}
