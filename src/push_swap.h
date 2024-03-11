/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/11 18:46:16 by mmosk         ########   odam.nl         */
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

# define MAX_DEPTH 6
# define JOLT 0x8888888888888888UL

# define EMPTY_DISAPPROVAL 0xFFFFFFFFFFFFFFFFUL

# define GAP_ALLOTMENT 0x02
# define GAP_INCREMENT 0x08

# define BREAK_ALLOTMENT 0x03
# define BREAK_INCREMENT 0x010

# define INTERFACE_INCREMENT 0x08
# define INTERFACE_DISGRACE 4
# define INTERFACE_GRACE 2

// # define REACH_ANGLE -1

# define MAX_OUTREACH_COST 0x600
# define BASE_REACH_COST 0xC00

# define B_DISAPPROVAL 0x200

# define RIFLE_START 0x8000

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef enum
{
	STACK_A = 0,
	STACK_B = 1
}	t_dir;

typedef enum inst
{
	NON = 0x0,
	_PA = 0x1,
	_SA = 0x2,
	_SB = 0x3,
	_SS = 0x4,
	_RA = 0x5,
	_RB = 0x6,
	_RR = 0x7,
	RRR = 0x8,
	RRB = 0x9,
	RRA = 0xA,
	_PB = 0xE,
	END = 0xF
}	t_inst;

//Braid this chain (pain)
typedef struct s_stack
{
	t_ulong	*val;
	t_uint	start;
	t_uint	end;
	t_uint	count;
}	t_stack;

typedef struct s_proposal
{
	t_ulong	dsc;
	t_ulong	dpp;
	t_uint	parent_number;
}	t_proposal;

typedef struct s_dsclist
{
	struct s_dsclist	*next;
	t_ulong				dsc;
}	t_dsclist;

typedef struct s_branch
{
	t_dsclist	dsclist;
	t_stack		*a;
	t_stack		*b;
}	t_branch;

typedef struct s_stackstate
{
	t_ulong	dsc;
	t_ulong	dpp;
}	t_stackstate;

typedef int				(*t_inst)(t_stack *a, t_stack *b);

////////////					Output functions					////////////

void			print_dsc(t_ulong dsc);
void			print_stacks(t_stack *a, t_stack *b);

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

////////////					Memory & Error management			////////////

void			free_stack(t_stack *stack);
void			exit_wrapper(void);

#endif