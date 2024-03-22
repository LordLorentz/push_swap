/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/22 15:06:07 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

//Prime number + modulo hash for testing!
//Multiply prime of position with prime of n, add into 1 //No.

// |a| * x! = factorial digit

t_hash	normalize_val(t_stack *stack, t_uint val)
{
	t_uint	current;
	t_hash	out;

	out = 0;
	current = val;
	while (current != END_OF_STACK)
	{
		if (current < val)
			out += 1;
		current = stack->val[current] & STACK_RIGHT;
	}
	return (out);
}

t_hash	factorialize_stack(t_stack *stack)
{
	t_uint	current;
	t_hash	out;
	t_hash	frag;

	out = 0;
	frag = MAX_FRAG;
	current = stack->start;
	while (current != END_OF_STACK)
	{
		out += normalize_val(stack, current) * factorial(frag);
		current = stack->val[current] & STACK_RIGHT;
		frag--;
	}
	return (out);
}

t_hash	hash_stacks(t_stack *a, t_stack *b)
{
	t_hash	hash;
	t_hash	modifier;
	t_uint	i;

	modifier = b->count;
	i = 0;
	while (i++ < modifier)
		pa(a, b);
	hash = factorialize_stack(a);
	hash |= modifier << MAX_FACTORIAL;
	i = 0;
	while (i++ < modifier)
		pb(a, b);
	return (hash);
}
