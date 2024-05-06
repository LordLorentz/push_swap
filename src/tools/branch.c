/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   branch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/14 13:05:51 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/06 15:13:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_branch	*make_branch(t_stack *stack, t_uint location)
{
	t_branch	*out;

	out = malloc(sizeof(t_branch));
	if (out == NULL)
		return (NULL);
	out->stack = clone_stack(stack);
	if (out->stack == NULL)
		return (free(out), NULL);
	out->dsclist = NULL;
	out->current = DSC_EMPTY;
	out->location = location;
	return (out);
}

//gnarly memory conflicts
void	free_branch(t_branch *branch)
{
	free_stack(branch->stack);
	free_dsclist(&branch->dsclist);
	free(branch);
}

t_branch	**make_hedge(t_stack *stack, t_uint hedge_size)
{
	t_branch	**hedge;
	t_uint		i;

	hedge = malloc(sizeof(t_branch *) * hedge_size);
	if (hedge == NULL)
		return (NULL);
	i = 0;
	while (i < hedge_size)
	{
		hedge[i] = make_branch(stack, i);
		if (hedge[i] == NULL)
			return (free_hedge(hedge, i), NULL);
		i++;
	}
	return (hedge);
}

void	free_hedge(t_branch **hedge, t_uint hedge_size)
{
	t_uint	i;

	i = 0;
	while (i < hedge_size)
	{
		free_branch(hedge[i]);
		i++;
	}
	free(hedge);
}
