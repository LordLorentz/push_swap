/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interpret_result.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 14:32:13 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 15:48:21 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "elucidate.h"

int	print_dpp(t_dpplist *test)
{
	t_dsclist	*dsclist;

	while (test != NULL)
	{
		dsclist = test->dsclist;
		if (ft_printf("--dpp: %p\n", (t_ulong)test->dpp) == -1)
			return (1);
		while (dsclist != NULL)
		{
			if (print_horizontal(dsclist->dsc))
				return (1);
			dsclist = dsclist->next;
		}
		if (ft_printf("\n") == -1)
			return (1);
		test = test->next;
	}
	return (0);
}

int	interpret_result(t_dpplist **test)
{
	size_t	i;

	i = 0;
	while (i < RESULT_SIZE)
	{
		if (print_dpp(test[i]))
			return (1);
		i++;
	}
	return (0);
}
