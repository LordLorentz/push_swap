/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eskarina.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:20:36 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/16 15:47:41 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline bool track_direction()

t_dpp	eskarina(t_uint val, t_uint count, t_uint size, t_mode mode)
{
	static t_uint	i = 0;
	static t_uint	prev = END_OF_STACK;
	t_dpp			out;

	if (val == END_OF_STACK)
	{
		i = 0;
		prev = val;
		return (0);
	}
	out = (mode == B);
	if (prev == END_OF_STACK && val != END_OF_STACK)
		out = wrap(val, size);
	else if ((dif(prev, val) != 1
			&& (prev < val ^ mode == B))
			|| (prev > val ^ mode == B))
	{
		out = wrap(dif(prev, val), size);
		if (prev > val)
			out += wrap(i, count);
	}
	i++;
	prev = val;
	return (out);
}
