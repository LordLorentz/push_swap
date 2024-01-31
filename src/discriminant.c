/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   discriminant.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 13:50:28 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/31 16:02:03 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const static t_inst	g_jumptable[16]
	= {
	NULL, &sa, &sb, &ss,
	&ra, &rb, &rr, &pa,
	&pb, &rrr, &rrb, &rra,
	&ss, &sb, &sa, NULL
};

t_ulong	iterate_discriminant(t_ulong discriminant)
{

}
