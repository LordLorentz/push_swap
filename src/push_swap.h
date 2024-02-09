/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/09 14:35:05 by mmosk         ########   odam.nl         */
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
# define STACK_RIGHT 0x00000000FFFFFFFFUL
# define STACK_LEFT 0xFFFFFFFF00000000UL

# define DSC_EMPTY 0x0000000000000000UL
# define DSC_END 0xFFFFFFFFFFFFFFFFUL
# define DSC_LAST 0x000000000000000FUL
# define DSC_BODY 0xFFFFFFFFFFFFFFF0UL
# define DSC_SIZE 4

# define MAX_DEPTH 7
# define JOLT 0x8888888888888888UL

# define EMPTY_DISAPPROVAL 0xFFFFFFFFFFFFFFFFUL
# define GAP_DISAPPROVAL 0x18
# define GAP_INCREMENT 1
# define BREAK_DISAPPROVAL 0x40
# define BREAK_INCREMENT 1

# define REACH_ANGLE -1
// # define MAX_OUTREACH_COST 12
# define BASE_REACH_COST 0x2000

# define RIFLE_START 0x2000

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef enum
{
	STACK_A = 0,
	STACK_B = 1
}	t_dir;

typedef struct s_stack
{
	t_ulong	*val;
	t_uint	start;
	t_uint	end;
	t_uint	count;
}	t_stack;

typedef struct s_stackstate
{
	t_ulong	dsc;
	t_ulong	dpp;
}	t_stackstate;

typedef int				(*t_inst)(t_stack *a, t_stack *b);

////////////					Output functions					////////////

void			print_dsc(t_ulong dsc, int size);
void			print_stacks(t_stack *a, t_stack *b);
void			debug_stacks(t_stack *a, t_stack *b);

////////////					Input handling						////////////

t_uint			*read_stack(char **input, t_uint size);
t_uint			*normalize_stack(int *stack, t_uint size);
t_stack			*create_stack(t_uint size, t_uint start, t_uint end, t_uint cn);

////////////					Inane Wizardry						////////////

t_stack			*curse_stack(t_uint *stack, t_uint size);
t_ulong			iter_dsc(t_ulong discriminant);
t_ulong			mk_dsc(t_uint depth);
t_ulong			inquisit(t_stack *a, t_stack *b, t_uint size);
int				scuttle_dsc(t_stack *a, t_stack *b, t_ulong prev, t_ulong next);
t_stackstate	run_cycle(t_stack *a, t_stack *b, t_ulong start, t_uint size);
void			agent_sort(t_stack *a, t_stack *b, t_uint size, t_uint depth);

////////////					Stack manipulation					////////////

int				pa(t_stack *a, t_stack *b);
int				pb(t_stack *a, t_stack *b);
int				ra(t_stack *a, t_stack *b);
int				rb(t_stack *a, t_stack *b);
int				rr(t_stack *a, t_stack *b);
int				rra(t_stack *a, t_stack *b);
int				rrb(t_stack *a, t_stack *b);
int				rrr(t_stack *a, t_stack *b);
int				sa(t_stack *a, t_stack *b);
int				sb(t_stack *a, t_stack *b);
int				ss(t_stack *a, t_stack *b);

void			ft_exit(void);

#endif