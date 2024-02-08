/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inquisition.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 20:04:07 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/08 21:02:15 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Algorithm specifications:
//--Takes one stack, and the total amount of integers in both stacks.
//--Returns a disapproval rating which is lower the easier to sort the input
//		stack is, and 0 if perfectly sorted.
//--_-Returns EMPTY_DISAPPROVAL if the stack is empty.
//--Speed is paramount.
//--Should show improvement within 6-8 instructions.

//O(n) = n

//None of the reach functions worked in the first place cause size varies lmao.
static inline t_ulong	get_reach(t_uint size, int i)
{
	const int	p = size / 2;
	const int	p2c = (p * p) + BASE_REACH_COST;
	const int	x_p = i - p;
	const int	ax2 = REACH_ANGLE * (x_p * x_p);

	return (ax2 + p2c);
}

// static inline t_ulong	get_reach(t_uint size, t_uint i)
// {
// 	const t_ulong	step_size = (size / MAX_OUTREACH_COST) + 1;
// 	t_ulong			current_step;

// 	if (i <= (size >> 1))
// 		current_step = i / step_size;
// 	else
// 		current_step = (size - i) / step_size;
// 	return (BASE_REACH_COST + current_step);
// }

// static inline t_ulong	get_reach(t_uint size, t_uint i)
// {
// 	static const t_ulong	max_reach = MAX_DEPTH / 2 - 1;

// 	if (i <= (size >> 1) && i > max_reach)
// 		return (BASE_REACH_COST + MAX_OUTREACH_COST);
// 	else if ((size - i) > max_reach)
// 		return (BASE_REACH_COST + MAX_OUTREACH_COST);
// 	return (BASE_REACH_COST);
// }

inline t_ulong	test_comb(t_uint left, t_uint right, t_uint size, t_uint i)
{
	t_ulong			disapproval;
	const t_ulong	reach = get_reach(size, i);

	disapproval = 0;
	if (left + 1 < right)
	{
		disapproval += GAP_DISAPPROVAL * BASE_REACH_COST;
		disapproval += (right - (left + 1)) * GAP_INCREMENT * BASE_REACH_COST;
	}
	else if (left + 1 > right)
	{
		disapproval += BREAK_DISAPPROVAL * reach;
		disapproval += ((left + 1) - right) * BREAK_INCREMENT * reach;
	}
	return (disapproval);
}

//Returns the disapproval rating for this stack.
inline t_ulong	get_disapproval(t_stack *stack, t_uint size, t_dir dir)
{
	t_uint	current;
	t_uint	next;
	t_ulong	disapproval;
	t_uint	i;

	if (__builtin_expect(stack->start == END_OF_STACK, 0))
		return (EMPTY_DISAPPROVAL);
	current = stack->start;
	if (stack->start <= (size >> 1))
		disapproval = stack->start;
	else
		disapproval = size - stack->start + 1;
	i = 0;
	while (__builtin_expect(current != stack->end, 1))
	{
		next = stack->val[current] & STACK_RIGHT;
		if (dir == STACK_A)
			disapproval += test_comb(current, next, size, i);
		else
			disapproval += test_comb(next, current, size, i);
		current = next;
		i++;
	}
	return (disapproval);
}

t_ulong	inquisit(t_stack *a, t_stack *b, t_uint size)
{
	const t_ulong	disapproval_a = get_disapproval(a, size, STACK_A);
	const t_ulong	disapproval_b = get_disapproval(b, size, STACK_B);
	t_ulong			out;

	out = disapproval_a;
	if (__builtin_expect(disapproval_b != EMPTY_DISAPPROVAL, 0))
		out += disapproval_b;
	return (out);
}

// static inline t_ulong	test_disapproval(t_uint left, t_uint right)
// {
// 	t_ulong			disapproval;
// 	t_ulong			gap_dis;
// 	t_ulong			gap_inc;
// 	t_ulong			break_dis;
// 	static t_uint	i = 0;

// 	disapproval = 0;
// 	gap_dis = 0;
// 	gap_inc = 0;
// 	break_dis = 0;
// 	disapproval += (left + 1 < right) * GAP_DISAPPROVAL;
// 	gap_dis += (left + 1 < right) * GAP_DISAPPROVAL;
// 	disapproval += (left + 1 < right) * (right - (left + 1)) * GAP_INCREMENT;
// 	gap_inc += (left + 1 < right) * (right - (left + 1)) * GAP_INCREMENT;
// 	disapproval += (left + 1 > right) * BREAK_DISAPPROVAL;
// 	break_dis += (left + 1 > right) * BREAK_DISAPPROVAL;
// 	if (disapproval)
// 	{
// 		ft_printf("\n__i: %u\n", i);
// 		ft_printf("__--Gap: %p\n", gap_dis + gap_inc);
// 		ft_printf("__--Break: %p\n", break_dis);
// 	}
// 	i++;
// 	return (disapproval);
// }

// //Returns the disapproval rating for this stack.
// t_ulong	inquisit(t_stack *a, t_uint size)
// {
// 	t_uint	current;
// 	t_ulong	disapproval;
// 	t_uint	i;

// 	if (a->start == END_OF_STACK)
// 		return (EMPTY_DISAPPROVAL);
// 	current = a->start;
// 	if (a->start < size / 2)
// 		disapproval = a->start;
// 	else
// 		disapproval = size - a->start + 1;
// 	ft_printf("\n--Start: %p\n", disapproval);
// 	i = 0;
// 	while (current != a->end)
// 	{
// 		disapproval += test_disapproval(current, a->val[current] & STACK_RIGHT)
// 			* (1 + (OUTREACH_COST * (i > REACH || size - i > REACH)));
// 		if ((OUTREACH_COST * (i > REACH || size - i > REACH)))
// 			ft_printf("  ^*2^!\n");
// 		current = a->val[current] & STACK_RIGHT;
// 		i++;
// 	}
// 	return (disapproval);
// }
