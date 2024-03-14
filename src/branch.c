/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   branch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/14 13:05:51 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/14 22:47:31 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_branch	init_branch(t_stack *a, t_stack *b, t_uint location, t_uint size)
{
	t_branch	*out;

	if (out == NULL)
		return (NULL);
	out->a = copy_stack(size, a);
	if (out->a == NULL)
		return (free(out), NULL);
	out->b = copy_stack(size, b);
	if (out->b == NULL)
		return (free(out->a), free(out), NULL);
	out->dsclist = NULL;
	out->location = location;
	return (out);
}
//gnarly memory conflicts
void	free_branch(t_branch branch)
{
	free_stack(branch.a);
	free_stack(branch.b);
	free_dsclist(branch->dsclist);
	free(branch);
}

t_branch	*grow_hedge(t_stack *a, t_stack *b, t_uint amount, t_uint size)
{

}

//memcpy branch from old buffer to new, then extend according to proposal
