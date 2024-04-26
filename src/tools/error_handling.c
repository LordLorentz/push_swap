/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 13:33:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/26 15:40:15 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_proposal(t_proposal proposal, char *prefix)
{
	t_uint	i;

	ft_printf(prefix);
	i = 0;
	while (i < PANEL_SIZE)
	{
		ft_printf("|%u: %p-", i, proposal.dpp[i]);
		i++;
	}
	ft_printf("\n%s|--parent: %u, dsc: %p\n", prefix, proposal.parent,
			proposal.dsc);
}

// void	debug_stacks(t_stack *a, t_stack *b)
// {
// 	t_ulong	current_a;
// 	t_ulong	current_b;
// 	int		brek = 0;
// 	t_uint	total = 0;

// 	current_a = a->start;
// 	current_b = b->start;
// 	if (a->start != END_OF_STACK)
// 	{
// 		current_a = a->val[a->start];
// 		total++;
// 	}
// 	if (b->start != END_OF_STACK)
// 	{
// 		current_b = b->val[b->start];
// 		total++;
// 	}
// 	ft_printf("\nS: %3u  E: %-3u|| S: %3u  E: %-3u\n",
// 		a->start, a->end, b->start, b->end);
// 	ft_printf("////     A    --    B     \\\\\\\\\n");
// 	while (brek != 2)
// 	{
// 		brek = 0;
// 		ft_printf("-_%10u  %10u  |", current_a >> 32,
// 			(current_a & STACK_RIGHT));
// 		if ((current_a & STACK_RIGHT) != END_OF_STACK)
// 		{
// 			current_a = a->val[current_a << 32 >> 32];
// 			total++;
// 		}
// 		else
// 			brek++;
// 		ft_printf("|  %-10u  %-10u_-\n", current_b >> 32,
// 			(current_b & STACK_RIGHT));
// 		if ((current_b & STACK_RIGHT) != END_OF_STACK)
// 		{
// 			current_b = b->val[current_b << 32 >> 32];
// 			total++;
// 		}
// 		else
// 			brek++;
// 	}
// 	ft_printf("TOTAL: %u\n", total);
// }

void	exit_wrapper(void)
{
	write(2, "Error!\n", 8);
	exit(1);
}
