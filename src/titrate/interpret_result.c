/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interpret_result.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 14:32:13 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/21 15:13:28 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "hashlist.h"

void	sum_hashlist(t_hashlist *list, t_ulong *unique, t_ulong *duplicate)
{
	if (list == NULL)
		return ;
	*unique += 1;
	*duplicate += list->count - 1;
	sum_hashlist(list->next, unique, duplicate);
}

int interpret_result(t_hashlist **result)
{
	size_t	i;
	t_ulong	unique;
	t_ulong	duplicate;

	unique = 0;
	duplicate = 0;
	i = 0;
	while (i < RESULT_SIZE)
	{
		sum_hashlist(result[i], &unique, &duplicate);
		i++;
	}
	if (ft_printf("Unique: %p\nDuplicate: %p\n", unique, duplicate) == -1)
		return (1);
	return (0);
}
