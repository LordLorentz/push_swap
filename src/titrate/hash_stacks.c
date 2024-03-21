/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/21 21:16:19 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "hashlist.h"

//Prime number + modulo hash for testing!
//Multiply prime of position with prime of n, add into 1 //No.

// |a| * x! = factorial digit

t_hash	normalize_hash(t_hash hash, t_hash offset)
{
	t_ulong	i;
	t_ulong	j;
	t_ulong	current;
	t_ulong	lowest;
	t_ulong	lowest_index;

	i = 0;
	while (i + offset < 16UL)
	{
		lowest = 16UL;
		j = offset;
		while (j < 16UL)
		{
			current = hash >> ((15UL - j) * 4UL) & 0xFUL;
			if (current < lowest && current >= i)
			{
				lowest = current;
				lowest_index = j;
			}
			j++;
		}
		hash = (hash & bit_not((0xFUL << ((15UL - lowest_index) * 4UL))))
			| (i++ << ((15UL - lowest_index) * 4UL));
	}
	return (hash >> ((15UL - offset) * 4UL) & 0xFUL);
}

t_ulong	factorialize_hash(t_ulong in)
{
	t_uint	i;
	t_ulong	out;

	i = 0;
	out = 0;
	while (i < 16)
	{
		out += normalize_hash(in, i) * factorial(15 - i);
		i++;
	}
	return (out);
}

//Only works if n <= 16
t_ulong	discern_stack(t_stack *stack)
{
	t_ulong	out;
	t_uint	current;

	out = 0;
	current = stack->start;
	while (current != END_OF_STACK)
	{
		out = out << 4UL;
		out |= current;
		current = stack->val[current] & STACK_RIGHT;
	}
	return (out);
}

t_ulong	hash_stacks(t_stack *a, t_stack *b)
{
	t_ulong	hash;

	hash = discern_stack(a);
	hash <<= (unsigned long)b->count * 4UL;
	hash |= discern_stack(b);
	hash = factorialize_hash(hash);
	hash |= (t_ulong)b->count << 48UL;
	return (hash);
}
