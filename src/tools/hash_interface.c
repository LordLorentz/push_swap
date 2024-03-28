/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/28 12:46:39 by mmosk         ########   odam.nl         */
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

//Hallelujah.
void	wrap(t_stack *a, t_stack *b, t_stack *interface)
{
	scuttle_dsc(interface, a, DSC_EMPTY, 0x0000000011111111UL);
	scuttle_dsc(interface, a, DSC_EMPTY, 0xA1A1A1A1A1A1A1A1UL);
	scuttle_dsc(interface, b, DSC_EMPTY, 0x0000000011111111UL);
	scuttle_dsc(interface, b, DSC_EMPTY, 0xA1A1A1A1A1A1A1A1UL);
}

void	unwrap(t_stack *a, t_stack *b, t_stack *interface)
{
	scuttle_dsc(interface, b, 0xA1A1A1A1A1A1A1A1UL, DSC_EMPTY);
	scuttle_dsc(interface, b, 0x0000000011111111UL, DSC_EMPTY);
	scuttle_dsc(interface, a, 0xA1A1A1A1A1A1A1A1UL, DSC_EMPTY);
	scuttle_dsc(interface, a, 0x0000000011111111UL, DSC_EMPTY);
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
	wrap(a, b, interface);
	hash = factorialize_stack(interface);
	unwrap(a, b, interface);
	return (hash);
}
