/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_discriminant.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 18:52:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/12 14:24:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char *const	g_stringtable[16]
	= {
	NULL, "pa\n", "sa\n", "sb\n",
	"ss\n", "ra\n", "rb\n", "rr\n",
	"rrr\n", "rrb\n", "rra\n", "ss\n",
	"sb\n", "sa\n", "pb\n", NULL
};

void	print_dsc(t_ulong dsc)
{
	const char	*current;
	int			shift;
	
	shift = sizeof(t_ulong) * 8 - DSC_SIZE;
	while ((dsc >> shift & DSC_LAST) == 0 && shift)
		shift -= DSC_SIZE;
	while (shift >= 0)
	{
		current = g_stringtable[(dsc >> shift) & DSC_LAST];
		if (current != NULL)
			ft_printf("%s", current);
		shift -= 4;
	}
}
