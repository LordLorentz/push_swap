/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jumptable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:45:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/01 13:53:02 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const static t_inst	g_jumptable[16]
	= {
	NULL, &pa, &sa, &sb,
	&ss, &ra, &rb, &rr,
	&rrr, &rrb, &rra, &ss,
	&sb, &sa, &pb, NULL
};
