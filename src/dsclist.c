/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsclist.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:04:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/13 19:34:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dsclist	*make_dsclist(t_dsc dsc)
{
	t_dsclist	*out;

	out = malloc(sizeof(t_dsclist));
	if (out == NULL)
		return (NULL);
	out->dsc = dsc;
	out->next = NULL;
	return (out);
}

void	free_dsclist(t_dsclist **head)
{
	if ((*head)->next != NULL)
		free_dsclist(&(*head)->next);
	free(*head);
	head = NULL;
}

t_dsclist	*append_dsclist(t_dsclist **head, t_dsc dsc)
{
	t_dsclist	*current;

	if (*head == NULL)
	{
		*head = make_dsclist(dsc);
		return (*head);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = make_dsclist(dsc);
	return (current->next);
}

void	overwrite_dsclist(t_dsclist *dst, t_dsclist *src)
{
	while (dst != NULL && src != NULL)
	{
		dst->dsc = src->dsc;
		dst = dst->next;
		src = src->next;
	}
}

int	print_dsclist(t_dsclist *list)
{
	while (list != NULL)
	{
		if (print_dsc(list->dsc) == -1)
			return (-1);
		list = list->next;
	}
	return (0);
}
