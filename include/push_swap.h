/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/09 13:54:33 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_math.h"

# define END_OF_STACK 0x3FFFFFUL

# define DSC_EMPTY 0x0000000000000000UL
# define DSC_END 0xFFFFFFFFFFFFFFFFUL
# define DSC_LAST 0x000000000000000FUL
# define DSC_BODY 0xFFFFFFFFFFFFFFF0UL
# define DSC_SIZE 4

# define MAX_DEPTH 6

# define EMPTY_DISAPPROVAL 0xFFFFFFFFFFFFFFFFUL
# define SORTED_DISAPPROVAL 0x0UL

# define PANEL_SIZE 3
# define HEDGE_SIZE 3

# define ORPHAN UINT_MAX

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef t_ulong			t_dsc;
typedef t_ulong			t_dpp;

typedef enum state
{
	DOWN = 1,
	UP = 2
}	t_state;

typedef enum mode
{
	A = 0,
	B = 1
}	t_mode;

typedef enum inum
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
}	t_inum;

//The "user" field should be considered uninitialized for any implementation.
//Use may differ per implementation.
typedef struct s_item
{
	t_uint	prev : 22;
	t_uint	next : 22;
	t_mode	container : 1;
	t_uint	user : 22;
}	t_item;

typedef struct s_stack
{
	t_item	*val;

	t_uint	head[2];
	t_uint	tail[2];
	t_uint	count[2];
	t_uint	size;
}	t_stack;

typedef struct s_proposal
{
	t_dsc	dsc;
	t_dpp	dpp[PANEL_SIZE];
	t_uint	parent;
}	t_proposal;

typedef struct s_dsclist
{
	struct s_dsclist	*next;
	t_dsc				dsc;
}	t_dsclist;

typedef struct s_branch
{
	t_dsclist	*dsclist;
	t_dsc		current;
	t_uint		location;
	t_stack		*stack;
}	t_branch;

typedef struct s_stackstate
{
	t_dsc	dsc;
	t_ulong	dpp;
}	t_stackstate;

typedef int				(*t_inst)(t_stack *);

typedef t_dpp			(*t_inquisitor)(t_stack *);

////////////					Input handling						////////////

t_uint			*read_stack(char **input, t_uint size);
t_uint			*normalize_stack(int *stack, t_uint size);

////////////					Inquisition							////////////

int				convene(t_stack *stack);

t_proposal		inquisit(t_stack *stack);

t_dpp			technoblade(t_stack *stack);
void			index_stack(t_stack *stack, t_mode mode);
t_dpp			interface(t_stack *stack, t_uint query);
t_uint			neighbour(t_stack *stack, t_uint query, t_state dir, t_mode m);

t_dpp			eskarina(t_stack *stack);
t_dpp			gossman(t_stack *stack);

////////////					Discriminant functions				////////////

t_dsc			mk_dsc(t_uint depth);
t_dsc			distil(t_dsc dsc);
t_dsc			iter_dsc(t_dsc discriminant);
int				scuttle_dsc(t_stack *stack, t_dsc prev, t_dsc next);
int				print_dsc(t_dsc dsc);

////////////					Discriminant lists					////////////

t_dsclist		*make_dsclist(t_dsc dsc);
void			free_dsclist(t_dsclist **head);
int				append_dsclist(t_dsclist **head, t_dsc dsc);
int				overwrite_dsclist(t_dsclist **dst, t_dsclist *src);
int				print_dsclist(t_dsclist *list);

////////////					Panel and proposal					////////////

t_proposal		init_proposal(t_uint panel_size);
void			init_panel(t_proposal panel[], t_uint panel_size);
void			insert_proposal(t_proposal panel[], t_proposal proposal);
bool			is_sorted(t_proposal panel[]);

////////////					Hedge and branch					////////////

t_branch		*make_branch(t_stack *stack, t_uint location);
void			free_branch(t_branch *branch);
t_branch		**make_hedge(t_stack *stack, t_uint hedge_size);
void			free_hedge(t_branch **hedge, t_uint hedge_size);
int				extend_hedge(t_branch **dst, t_branch **src, t_proposal p[]);


////////////					Stack manipulation					////////////

t_stack			*create_stack(t_uint size);
t_stack			*clone_stack(t_stack *stack);
t_stack			*copy_stack(t_stack *dst, t_stack *src);
t_stack			*curse_stack(t_uint *stack, t_uint size);
void			free_stack(t_stack *stack);

////////////					Push_Swap instructions				////////////

int				pa(t_stack *stack);
int				pb(t_stack *stack);
int				ra(t_stack *stack);
int				rb(t_stack *stack);
int				rr(t_stack *stack);
int				rra(t_stack *stack);
int				rrb(t_stack *stack);
int				rrr(t_stack *stack);
int				sa(t_stack *stack);
int				sb(t_stack *stack);
int				ss(t_stack *stack);

////////////					Debugging							////////////

int				print_horizontal(t_dsc dsc);
void			print_stacks(t_stack *stack);
void			print_proposal(t_proposal proposal, char *prefix);
int				print_cycle(t_stack *stack, t_dsc start);
int				print_rifle(t_stack *stack, t_uint depth);

////////////					Error management					////////////

void			exit_wrapper(void);

#endif