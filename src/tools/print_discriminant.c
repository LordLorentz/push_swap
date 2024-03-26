/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_discriminant.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 18:52:29 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/26 12:38:02 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char *const	g_stringtable[16]
	= {
	NULL, "pa", "sa", "sb",
	"ss", "ra", "rb", "rr",
	"rrr", "rrb", "rra", "ss",
	"sb", "sa", "pb", NULL
};

int	print_dsc(t_dsc dsc)
{
	const char	*current;
	int			shift;

	shift = sizeof(t_dsc) * 8 - DSC_SIZE;
	while ((dsc >> shift & DSC_LAST) == 0 && shift)
		shift -= DSC_SIZE;
	while (shift >= 0)
	{
		current = g_stringtable[(dsc >> shift) & DSC_LAST];
		if (current != NULL)
			if (ft_printf("%s\n", current) == -1)
				return (1);
		shift -= 4;
	}
	return (0);
}

int	print_horizontal(t_dsc dsc)
{
	const char	*current;
	int			shift;

	shift = sizeof(t_dsc) * 8 - DSC_SIZE;
	while ((dsc >> shift & DSC_LAST) == 0 && shift)
		shift -= DSC_SIZE;
	while (shift >= 0)
	{
		current = g_stringtable[(dsc >> shift) & DSC_LAST];
		if (current != NULL)
			if (ft_printf("_%s", current) == -1)
				return (1);
		shift -= 4;
	}
	if (ft_printf("_||") == -1)
		return (1);
	return (0);
}
