/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interpret_result.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 14:32:13 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/26 12:36:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

void	sum_hashlist(t_hashlist *list, t_ulong *unique, t_ulong *duplicate)
{
	if (list == NULL)
		return ;
	*unique += 1;
	*duplicate += list->count - 1;
	sum_hashlist(list->next, unique, duplicate);
}

int	is_present(t_hashlist *control, t_hashlist *test)
{
	while (test != NULL)
	{
		if (control->hash == test->hash)
			return (1);
		test = test->next;
	}
	return (0);
}

int	print_missing(t_hashlist *control, t_hashlist **test)
{
	while (control != NULL)
	{
		if (is_present(control, *test) == 0)
			if (ft_printf("--Unique hash missing!\n--_Hash: %p, dsc: %p\n",
					(t_ulong)control->hash, control->dsclist->dsc) == -1)
				return (1);
		control = control->next;
	}
	return (0);
}

int	print_duplicate(t_hashlist *test)
{
	t_dsclist	*dsclist;

	while (test != NULL)
	{
		if (test->count != 1)
		{
			dsclist = test->dsclist;
			if (ft_printf("--Dulicate hash: %p\n", (t_ulong)test->hash) == -1)
				return (1);
			while (dsclist != NULL)
			{
				if (print_horizontal(dsclist->dsc))
					return (1);
				dsclist = dsclist->next;
			}
			if (ft_printf("\n") == -1)
				return (1);
		}
		test = test->next;
	}
	return (0);
}

int	interpret_result(t_hashlist **control, t_hashlist **test)
{
	size_t	i;
	t_ulong	control_un;
	t_ulong	control_dup;
	t_ulong	unique;
	t_ulong	duplicate;

	unique = 0;
	duplicate = 0;
	control_un = 0;
	control_dup = 0;
	i = 0;
	while (i < RESULT_SIZE)
	{
		if (print_missing(control[i], &test[i]))
			return (1);
		if (print_duplicate(test[i]))
			return (1);
		sum_hashlist(control[i], &control_un, &control_dup);
		sum_hashlist(test[i], &unique, &duplicate);
		i++;
	}
	if (ft_printf("Unique: %p -> %p\nDuplicate: %p -> %p\n",
			control_un, unique, control_dup, duplicate) == -1)
		return (1);
	return (0);
}
