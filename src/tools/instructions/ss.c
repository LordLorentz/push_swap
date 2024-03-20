/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ss.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:24:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/06 15:44:52 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack *a, t_stack *b)
{
	if (__builtin_expect(sa(a, b), 0))
		return (1);
	if (__builtin_expect(sb(a, b), 0))
		return (sa(a, b), 1);
	return (0);
}
