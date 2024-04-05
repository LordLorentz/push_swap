/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:20:36 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/05 16:13:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Arithmetic function to properly map absolute difference to circular difference
//put in math library?
static inline t_uint	wrap_dif(t_uint dif, t_uint size)
{
	return (
		(dif <= (size / 2)) * dif
		+ (dif > (size / 2)) * (size - dif)
		);
}

//Let's see if the Fools can beat Vorbis, the Exquisitor.

//Gotta add a->start increment.
//Write dif

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
	out = 0;
	if (prev + 1 < val && mode == A)
	{
		out += wrap_dif(val - prev + 1, count);
		out += wrap_dif(i, count);
	}
	if (prev + 1 > val && mode == B)
	{
		out += wrap_dif(prev + 1 - val, count);
		out += wrap_dif(i, count);
	}
	i++;
	prev = val;
	return (out);
}

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
	if (prev + 1 > val && mode == A)
	{
		out += wrap_dif(prev + 1 - val, count);
		out += wrap_dif(i, count);
	}
	if (prev + 1 < val && mode == B)
	{
		out += wrap_dif(val - prev + 1, count);
		out += wrap_dif(i, count);
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

	out = 0;
	if (prev == END_OF_STACK && mode == A)
		a_prime = val;
	if (prev == END_OF_STACK && mode == B)
	{
		out = wrap_dif()
		a_prime = 0;
	}
	prev = val;
	return (out);
}
