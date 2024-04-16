/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:20:36 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/16 14:49:29 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Let's see if the Fools can beat Vorbis, the Exquisitor.
//An even match, in the end.

//Gotta add a->start increment.
//The fools are foolish, whad'ya know.

//Is not recognizing 0 5 4 3 2 1.

//Deserves punishment.
t_dpp	chucklenuts(t_uint val, t_uint count, t_uint size, t_mode mode)
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

//chucklenuts ate dingy wat do?
//mitosis.
t_dpp	dingy(t_uint val, t_uint count, t_uint size, t_mode mode)
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
	out = 0;
	if (prev == END_OF_STACK && val != END_OF_STACK)
		out = wrap(val, size);
	else if ((dif(prev, val) != 1
			&& (prev < val ^ mode == B))
			|| (prev > val ^ mode == B))
	{
		out = wrap(dif(prev, val), size);
		if (out != 0)
			out += wrap(i, count);
	}
	i++;
	prev = val;
	return (out);
}

t_dpp	carter(t_uint val, t_uint count, t_uint size, t_mode mode)
{
	static t_uint	prev = END_OF_STACK;
	static t_uint	a_prime;
	t_dpp			out;

	(void)count;
	out = 0;
	if (prev == END_OF_STACK && val != END_OF_STACK)
		out += wrap(val, size);
	if (prev == END_OF_STACK && mode == A)
		a_prime = val;
	if (prev == END_OF_STACK && mode == B)
	{
		if (a_prime != END_OF_STACK && val != END_OF_STACK)
			out += wrap(dif(a_prime, val), size);
		a_prime = 0;
	}
	prev = val;
	return (out);
}
