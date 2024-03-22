/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   titrate.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 16:01:47 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/22 18:04:20 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TITRATE_H
# define TITRATE_H

# include <stdint.h>

# ifdef UINT128MAX

#  define STACK_SIZE 32ULL
#  define MAX_FRAG 31ULL
#  define RESULT_SIZE 0x1000000UL
#  define MAX_FACTORIAL 120ULL

#  ifndef TITRATE_DEPTH
#   define TITRATE_DEPTH 7
#  endif

typedef unsigned long long	t_hash;

# else

#  define STACK_SIZE 16UL
#  define MAX_FRAG 15UL
#  define RESULT_SIZE 0x1000UL
#  define MAX_FACTORIAL 48UL

#  ifndef TITRATE_DEPTH
#   define TITRATE_DEPTH 3
#  endif

typedef unsigned long		t_hash;

# endif

typedef struct s_hashlist
{
	t_hash				hash;
	unsigned int		count;
	t_dsclist			*dsclist;
	struct s_hashlist	*next;
}	t_hashlist;

////////////					Logic								////////////

t_ulong		hash_stacks(t_stack *a, t_stack *b);
int 		interpret_result(t_hashlist **result);

////////////					Control systems						////////////

t_dsc		inc_dsc(t_dsc discriminant);
int			control_rifle(t_stack *a, t_stack *b, t_uint depth, t_hashlist **s);

////////////					Test systems						////////////

int			test_rifle(t_stack *a, t_stack *b, t_uint depth, t_hashlist **s);

////////////					Hashlists							////////////

t_hashlist	*make_hashlist(t_hash hash, t_dsc dsc);
void		free_hashlist(t_hashlist *list);
void		free_hashlist_arr(t_hashlist **arr, size_t size);
int			append_hashlist(t_hashlist **head, t_hash hash, t_dsc dsc);
int			insert_hash(t_hashlist **head, t_hash hash, t_dsc dsc);

#endif
