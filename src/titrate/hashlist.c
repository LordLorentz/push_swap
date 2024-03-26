/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashlist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 21:52:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/25 22:22:11 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

t_hashlist	*make_hashlist(t_hash hash, t_dsc dsc)
{
	t_hashlist	*out;

	out = malloc(sizeof(t_hashlist));
	if (out == NULL)
		return (NULL);
	out->dsclist = make_dsclist(dsc);
	if (out->dsclist == NULL)
		return (free(out), NULL);
	out->hash = hash;
	out->count = 1;
	out->next = NULL;
	return (out);
}

void	free_hashlist(t_hashlist *list)
{
	if (list == NULL)
		return ;
	if (list->next != NULL)
		free_hashlist(list->next);
	free_dsclist(&list->dsclist);
	free(list);
}

void	free_hashlist_arr(t_hashlist **arr, size_t size)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		free_hashlist(arr[i]);
		i++;
	}
	free(arr);
}

int	append_hashlist(t_hashlist **head, t_hash hash, t_dsc dsc)
{
	t_hashlist	*current;

	if (*head == NULL)
	{
		*head = make_hashlist(hash, dsc);
		if (*head == NULL)
			return (1);
		return (0);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = make_hashlist(hash, dsc);
	if (current->next == NULL)
		return (1);
	return (0);
}

int	insert_hash(t_hashlist **head, t_hash hash, t_dsc dsc)
{
	t_hashlist	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->hash == hash)
		{
			current->count += 1;
			if (append_dsclist(&current->dsclist, dsc) == NULL)
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (append_hashlist(head, hash, dsc));
}
