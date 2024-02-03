/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/03 20:11:24 by mmosk         ########   odam.nl         */
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

# define DSC_START 0x0000000011111111UL
# define DSC_END 0xFFFFFFFFFFFFFFFFUL
# define DSC_LAST 0x000000000000000FUL
# define DSC_BODY 0xFFFFFFFFFFFFFFF0UL
# define DSC_SIZE 4

# define GAP_DISAPPROVAL 4
# define GAP_INCREMENT 2
# define BREAK_DISAPPROVAL 8
# define INLAND_MULTIPLIER 2
# define INLAND_DISTANCE 10

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_stack
{
	t_ulong	*val;
	t_uint	start;
	t_uint	end;
}	t_stack;

typedef void			(*t_inst)(t_stack *a, t_stack *b);

////////////					Input handling						////////////

t_uint			*read_stack(char **input, t_uint size);
t_uint			*normalize_stack(int *stack, t_uint size);
t_stack			*create_stack(t_uint size, t_uint start, t_uint end);
t_stack			*curse_stack(t_uint *stack, t_uint size);

////////////					Discriminant Wizardry				////////////

t_ulong			iter_dsc(t_ulong discriminant);

////////////					Stack manipulation					////////////

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