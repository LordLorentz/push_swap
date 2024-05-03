/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:56:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 17:26:14 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_cycle(t_stack *stack, t_dsc start)
{
	t_dsc	current_dsc;
	t_dsc	prev_dsc;

	while (scuttle_dsc(stack, DSC_EMPTY, start))
	{
		ft_printf("__--dsc: %p\n", start);
		start = iter_dsc(start);
	}
	ft_printf("--dsc: %p\n", start);
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		while (scuttle_dsc(stack, prev_dsc, current_dsc))
		{
			ft_printf("__--dsc: %p\n", current_dsc);
			current_dsc = iter_dsc(current_dsc);
		}
		ft_printf("--dsc: %p\n", current_dsc);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(stack, prev_dsc, DSC_EMPTY);
	return (0);
}

int	print_rifle(t_stack *stack, t_uint depth)
{
	t_uint	size;

	print_stacks(stack);
	size = 1;
	while (size <= depth)
	{
		if (print_cycle(stack, mk_dsc(size)))
			return (1);
		size++;
	}
	return (0);
}
