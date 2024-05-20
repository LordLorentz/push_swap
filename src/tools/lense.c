/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lense.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 13:05:23 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/20 13:55:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lense	make_lense(t_uint size)
{
	t_lense out;
	t_uint	i;

	(void)size;
	out.bias[0] = 0;
	out.focus[0] = 2;
	i = 1;
	while (i < PANEL_SIZE)
	{
		out.bias[i] = i;
		out.focus[i] = i + 2;
		i++;
	}
	return (out);
}

static inline void	align_target(t_lense lense[], t_uint target)
{
	lense->bias[target] = (lense->bias[target] + 1) % lense->focus[target];
}

int	align_lense(t_lense lense[], t_proposal panel[])
{
	t_uint	i;
	int		out;

	i = 0;
	out = 0;
	while (i < PANEL_SIZE)
	{
		if (panel[i].dsc == DSC_EMPTY)
		{
			align_target(lense, i);
			out++;
		}
		i++;
	}
	return (out);
}
