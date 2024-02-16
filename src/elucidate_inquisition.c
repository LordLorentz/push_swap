/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elucidate_inquisition.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 20:04:07 by mmosk         #+#    #+#                 */
/*   Updated: 2024/02/15 14:24:28 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//O(n) = n

//Arithmetic function to properly map absolute difference to circular difference
static inline t_uint	wrap_dif(t_uint dif, t_uint size)
{
	return (
		(dif <= (size / 2)) * dif
		+ (dif > (size / 2)) * (size - dif)
		);
}

//Equation specifications:
//--Takes the amount of entries in a stack, and the position of the query point.
//--Returns a value that is higher the closer i is to count / 2.
static inline t_ulong	get_reach(t_uint size, t_uint i)
{
	const t_ulong	step_height = (MAX_OUTREACH_COST / (size / 2));
	const t_ulong	current_step = (wrap_dif(i, size) + 1) * step_height;

	return (BASE_REACH_COST + current_step);
}

static inline t_ulong	test_comb(t_uint left, t_uint right,
	t_ulong reach, t_uint size, int print)
{
	t_ulong			disapproval;
	static t_ulong	gap_dpp;
	static t_ulong	gap_inc;
	static t_ulong	break_dpp;
	static t_ulong	break_inc;

	disapproval = 0;
	if (left + 1 < right)
	{
		disapproval += GAP_DISAPPROVAL * BASE_REACH_COST;
		disapproval += wrap_dif(right - (left + 1), size)
			* GAP_INCREMENT * BASE_REACH_COST;
	}
	else if (left + 1 > right)
	{
		disapproval += BREAK_DISAPPROVAL * reach;
		disapproval += wrap_dif((left + 1) - right, size)
			* BREAK_INCREMENT * reach;
	}
	if (left + 1 < right)
	{
		gap_dpp += GAP_DISAPPROVAL * BASE_REACH_COST;
		gap_inc += wrap_dif(right - (left + 1), size)
			* GAP_INCREMENT * BASE_REACH_COST;
	}
	else if (left + 1 > right)
	{
		break_dpp += BREAK_DISAPPROVAL * reach;
		break_inc += wrap_dif((left + 1) - right, size)
			* BREAK_INCREMENT * reach;
	}
	if (print)
	{
		ft_printf("--_|gap_dpp: \t%10p	\n--_|gap_inc: \t%10p	\n--_|break_dpp: \t%10p	\n--_|break_inc: \t%10p	\n",
			gap_dpp, gap_inc, break_dpp, break_inc);
		gap_dpp = gap_inc = break_dpp = break_inc = 0;
	}
	return (disapproval);
}

//Algorithm specifications:
//--Takes one stack, and the total amount of integers in both stacks.
//--Returns a disapproval rating which is lower the easier to sort the input
//		stack is, and 0 if perfectly sorted.
//--_-Returns EMPTY_DISAPPROVAL if the stack is empty.
//--Should show smooth improvement within 6-8 instructions.
//--Speed is paramount.
static inline t_ulong	get_disapproval(t_stack *stack, t_uint size, t_dir dir)
{
	t_uint	current;
	t_uint	next;
	t_ulong	disapproval;
	t_ulong	b_disapproval = 0;
	t_uint	i;
	t_ulong	reach;

	if (__builtin_expect(stack->start == END_OF_STACK, 0))
		return (EMPTY_DISAPPROVAL);
	current = stack->start;
	disapproval = wrap_dif(stack->start, size);
	i = 0;
	while (__builtin_expect(current != stack->end, 1))
	{
		next = stack->val[current] & STACK_RIGHT;
		reach = get_reach(stack->count, i++);
		if (dir == STACK_A)
			disapproval += test_comb(current, next, reach, size, 0);
		else if (dir == STACK_B)
		{
			disapproval += test_comb(next, current, reach, size, 0) + B_DISAPPROVAL;
			b_disapproval += B_DISAPPROVAL;
		}
		current = next;
	}
	reach = get_reach(stack->count, i);
	if (current != stack->end && dir == STACK_A)
		disapproval += test_comb(stack->end, stack->start, reach, size, 0);
	else if (current != stack->end)
		disapproval += test_comb(stack->start, stack->end, reach, size, 0);
	test_comb(0, 0, 0, 0, 1);
	return (disapproval);
}

t_ulong	elucidate(t_stack *a, t_stack *b, t_uint size)
{
	const t_ulong	disapproval_a = get_disapproval(a, size, STACK_A);
	ft_printf("--A_dpp: \t%10p	\n", disapproval_a);
	const t_ulong	disapproval_b = get_disapproval(b, size, STACK_B);
	ft_printf("--B_dpp: \t%10p	\n", disapproval_b);
	t_ulong			out;
	t_ulong			interface = 0;

	out = disapproval_a;
	if (__builtin_expect(disapproval_b != EMPTY_DISAPPROVAL, 0))
	{
		out += disapproval_b;
		if (a->start + 1 != (a->val[a->start] & STACK_RIGHT))
		{
			if (a->start > b->start + INTERFACE_GRACE)
				interface += wrap_dif((a->start - b->start) - INTERFACE_GRACE, size)
					* INTERFACE_INCREMENT * BASE_REACH_COST;
			else if (b->start > a->start + INTERFACE_GRACE)
				interface += wrap_dif((b->start - a->start) - INTERFACE_GRACE, size)
					* INTERFACE_INCREMENT * BASE_REACH_COST;
		}
		else
			interface += (size / INTERFACE_DISGRACE) * BASE_REACH_COST;
		ft_printf("--Interface: \t%10p	\n", interface);
	}
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
// 	}// static inline t_ulong	get_reach(t_uint size, t_uint i)
// {
// 	const t_ulong	step_size = (size / MAX_OUTREACH_COST) + 1;
// 	t_ulong			current_step;

// 	if (i <= (size >> 1))
// 		current_step = i / step_size;
// 	else
// 		current_step = (size - i) / step_size;
// 	return (BASE_REACH_COST + current_step);
// }
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

// static inline t_ulong	get_reach(t_uint count, int i)
// {
// 	const int	p = count >> 1;
// 	const int	p2c = (p * p) + BASE_REACH_COST;
// 	const int	x_p = i - p;
// 	const int	ax2 = REACH_ANGLE * (x_p * x_p);

// 	return (ax2 + p2c);
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