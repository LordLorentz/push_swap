/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:44:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/26 15:24:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define END_OF_STACK UINT_MAX

typedef unsigned int t_uint;

////////////					Input handling						////////////

t_uint	*read_stack(char **input, t_uint size);
t_uint	*normalize_stack(int *stack, t_uint size);
t_uint	*curse_stack(t_uint *stack, t_uint size, t_uint *start);

void	ft_exit(void);

#endif