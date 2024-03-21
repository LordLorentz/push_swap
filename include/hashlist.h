/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashlist.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 16:01:47 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/21 14:58:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHLIST_H
# define HASHLIST_H

# define RESULT_SIZE 0x100000UL

typedef struct s_hashlist
{
	unsigned long		hash;
	unsigned int		count;
	struct s_hashlist	*next;
}	t_hashlist;

t_hashlist	*make_hashlist(t_ulong hash);
void		free_hashlist(t_hashlist *list);
void		free_hashlist_arr(t_hashlist **arr, size_t size);
int			hashlist_append(t_hashlist **head, t_ulong hash);
int			insert_hash(t_hashlist **head, t_ulong hash);

#endif
