/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/28 12:29:40 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_hash	normalize_val(t_stack *stack, t_uint val)
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

static t_hash	factorialize_stack(t_stack *stack)
{
	t_uint	current;
	t_hash	out;
	t_hash	frag;

	out = 0;
	frag = FRAG_MAX;
	current = stack->start;
	while (current != END_OF_STACK)
	{
		out += normalize_val(stack, current) * factorial(frag);
		current = stack->val[current] & STACK_RIGHT;
		frag--;
	}
	return (out);
}

void	interlace(t_stack *stack, t_stack *interface, t_dir dir)
{
	t_uint	prev;
	t_uint	current;
	t_uint	next;
	t_uint	i;

	if (dir == DOWN)
		current = stack->start;
	else
		current = stack->end;
	prev = interface->end;
	if (prev != END_OF_STACK)
		interface->val[prev] = (interface->val[prev] & STACK_LEFT) | current;
	i = 0;
	while (i < INTERFACE_SIZE / 4)
	{
		if (dir == DOWN)
			next = stack->val[current] & STACK_RIGHT;
		else if (dir == UP)
			next = (stack->val[current] & STACK_LEFT) >> 32UL;
		interface->val[current] = ((t_ulong)prev << 32UL) | next;
		prev = current;
		current = next;
		i++;
	}
	interface->val[prev] = (interface->val[prev] & STACK_LEFT) | END_OF_STACK;
}

//O(n) = 1/2 * n^2 + n

//Remember to free/init
t_hash	hash_interface(t_stack *a, t_stack *b, t_uint size, t_mode mode)
{
	static t_stack	*interface = 0;
	t_hash			hash;

	if (mode == INIT)
	{
		interface = create_stack(size, END_OF_STACK, END_OF_STACK, 0);
		if (interface == NULL)
			return (1);
		return (0);
	}
	else if (mode == FREE)
	{
		free_stack(interface);
		return (0);
	}
	if (a->count < INTERFACE_SIZE / 2 || b->count < INTERFACE_SIZE / 2)
		return (HASH_INVALID);
	interlace(a, interface, DOWN);
	interlace(a, interface, UP);
	interlace(b, interface, DOWN);
	interlace(b, interface, UP);
	hash = factorialize_stack(interface);
	return (hash);
}
