/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dpplist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 21:52:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 13:16:26 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "elucidate.h"

t_dpplist	*make_dpplist(t_dpp dpp, t_dsc dsc)
{
	t_dpplist	*out;

	out = malloc(sizeof(t_dpplist));
	if (out == NULL)
		return (NULL);
	out->dsclist = make_dsclist(dsc);
	if (out->dsclist == NULL)
		return (free(out), NULL);
	out->dpp = dpp;
	out->count = 1;
	out->next = NULL;
	return (out);
}

void	free_dpplist(t_dpplist *list)
{
	if (list == NULL)
		return ;
	if (list->next != NULL)
		free_dpplist(list->next);
	free_dsclist(&list->dsclist);
	free(list);
}

void	free_dpplist_arr(t_dpplist **arr, size_t size)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		free_dpplist(arr[i]);
		i++;
	}
	free(arr);
}

int	append_dpplist(t_dpplist **head, t_dpp dpp, t_dsc dsc)
{
	t_dpplist	*current;

	if (*head == NULL)
	{
		*head = make_dpplist(dpp, dsc);
		if (*head == NULL)
			return (1);
		return (0);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = make_dpplist(dpp, dsc);
	if (current->next == NULL)
		return (1);
	return (0);
}

int	insert_dpp(t_dpplist **head, t_dpp dpp, t_dsc dsc)
{
	t_dpplist	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->dpp == dpp)
		{
			current->count += 1;
			if (append_dsclist(&current->dsclist, dsc))
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (append_dpplist(head, dpp, dsc));
}
