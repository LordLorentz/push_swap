/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 13:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 14:16:29 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
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

void	ft_exit(void)
{
	ft_printf("Error!\n");
	exit(1);
}
