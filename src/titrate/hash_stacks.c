/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 12:09:19 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

//Prime number + modulo hash for testing!
//Multiply prime of position with prime of n, add into 1 //No.

// |a| * x! = factorial digit

static t_hash	normalize_val(t_stack *stack, t_uint val)
{
	t_uint	current;
	t_uint	i;
	t_hash	out;

	out = 0;
	current = val;
	i = 0;
	while (i < stack->count[A])
	{
		if (current < val)
			out += 1;
		current = stack->val[current].next;
		i++;
	}
	return (out);
}

static t_hash	factorialize_stack(t_stack *stack)
{
	t_uint	current;
	t_uint	i;
	t_hash	out;
	t_hash	frag;

	out = 0;
	frag = FRAG_MAX;
	current = stack->head[A];
	i = 0;
	while (i < stack->count[A])
	{
		out += normalize_val(stack, current) * factorial(frag);
		current = stack->val[current].next;
		frag--;
		i++;
	}
	return (out);
}

t_hash	hash_stacks(t_stack *stack)
{
	t_hash	hash;
	t_hash	modifier;
	t_uint	i;

	modifier = stack->count[B];
	i = 0;
	while (i++ < modifier)
		pa(stack);
	hash = factorialize_stack(stack);
	hash |= modifier << MAX_FACTORIAL;
	i = 0;
	while (i++ < modifier)
		pb(stack);
	return (hash);
}
