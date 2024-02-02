/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jumptable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:45:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/02 17:39:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Jumptable for push_swap instructions
// f() ^ 0xF = `f()  
const static t_inst	g_jumptable[16]
	= {
	NULL, &pa, &sa, &sb,
	&ss, &ra, &rb, &rr,
	&rrr, &rrb, &rra, &ss,
	&sb, &sa, &pb, NULL
};
