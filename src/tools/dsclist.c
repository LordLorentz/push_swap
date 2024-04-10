/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsclist.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:04:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/08 21:58:45 by mmosk         ########   odam.nl         */
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
	if (*head != NULL && (*head)->next != NULL)
		free_dsclist(&(*head)->next);
	free(*head);
	*head = NULL;
}

int	append_dsclist(t_dsclist **head, t_dsc dsc)
{
	t_dsclist	*current;

	if (*head == NULL)
	{
		*head = make_dsclist(dsc);
		if (*head == NULL)
			return (1);
		return (0);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = make_dsclist(dsc);
	if (current->next == NULL)
		return (1);
	return (0);
}

int	overwrite_dsclist(t_dsclist **dst, t_dsclist *src)
{
	while (src != NULL)
	{
		if (*dst == NULL)
		{
			*dst = make_dsclist(src->dsc);
			if (*dst == NULL)
				return (1);
		}
		else
		{
			(*dst)->dsc = src->dsc;
		}
		dst = &(*dst)->next;
		src = src->next;
	}
	return (0);
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
