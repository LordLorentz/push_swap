/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashlist.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 16:01:47 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/21 21:18:20 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHLIST_H
# define HASHLIST_H

# include <stdint.h>

# ifdef UINT128MAX

#  define STACK_SIZE 24ULL
#  define FRAG_WIDTH 5ULL
#  define RESULT_SIZE 0x1000000UL

typedef unsigned long long	t_hash;

# else

#  define STACK_SIZE 16UL
#  define FRAG_WIDTH 4UL
#  define RESULT_SIZE 0x1000UL

typedef unsigned long		t_hash;

# endif

typedef struct s_hashlist
{
	t_hash				hash;
	unsigned int		count;
	struct s_hashlist	*next;
}	t_hashlist;

t_hashlist	*make_hashlist(t_hash hash);
void		free_hashlist(t_hashlist *list);
void		free_hashlist_arr(t_hashlist **arr, size_t size);
int			hashlist_append(t_hashlist **head, t_hash hash);
int			insert_hash(t_hashlist **head, t_hash hash);

#endif
