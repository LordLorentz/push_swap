/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elucidate.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 16:01:47 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 15:49:44 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TITRATE_H
# define TITRATE_H

# include <stdint.h>

# define STACK_SIZE 8UL
# define RESULT_SIZE 0x1000UL

# ifndef TITRATE_DEPTH
#  define TITRATE_DEPTH 4
# endif


typedef struct s_dpplist
{
	t_dpp				dpp;
	unsigned int		count;
	t_dsclist			*dsclist;
	struct s_dpplist	*next;
}	t_dpplist;

////////////					Logic								////////////

int			interpret_result(t_dpplist **test);

////////////					Test systems						////////////

t_dpp		investigate(t_stack *a, t_stack *b, t_uint size);
int			test_rifle(t_stack *a, t_stack *b, t_uint depth, t_dpplist **s);

////////////					dpplists							////////////

t_dpplist	*make_dpplist(t_dpp dpp, t_dsc dsc);
void		free_dpplist(t_dpplist *list);
void		free_dpplist_arr(t_dpplist **arr, size_t size);
int			append_dpplist(t_dpplist **head, t_dpp dpp, t_dsc dsc);
int			insert_dpp(t_dpplist **head, t_dpp dpp, t_dsc dsc);

#endif
