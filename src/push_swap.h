/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/02 14:20:51 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf.h"

# define END_OF_STACK 0xFFFFFFFFUL

# if ITERATIONS < 1
#  undef ITERATIONS
# endif

# if ITERATIONS > 16
#  undef ITERATIONS
# endif

# ifndef ITERATIONS
#  define ITERATIONS 8
# endif

# define DSC_START 0x1111111111111111UL
# define DSC_END 0xFFFFFFFFFFFFFFFFUL
# define DSC_LAST 0x000000000000000FUL
# define DSC_SIZE 4

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_stack
{
	t_ulong	*val;
	t_uint	start;
	t_uint	end;
}	t_stack;

////////////					Input handling						////////////

t_uint			*read_stack(char **input, t_uint size);
t_uint			*normalize_stack(int *stack, t_uint size);
t_stack			*curse_stack(t_uint *stack, t_uint size);

////////////					Stack manipulation					////////////

t_stack			*create_stack(t_uint size, t_uint start, t_uint end);

typedef void			(*t_inst)(t_stack *a, t_stack *b);

void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a, t_stack *b);
void			rb(t_stack *a, t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a, t_stack *b);
void			rrb(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sa(t_stack *a, t_stack *b);
void			sb(t_stack *a, t_stack *b);
void			ss(t_stack *a, t_stack *b);

void			ft_exit(void);

#endif