/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_cycle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:56:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/22 11:43:58 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

int	test_cycle(t_stack *stack, t_dsc start, t_hashlist **result)
{
	t_dsc	current_dsc;
	t_dsc	prev_dsc;
	t_hash	hash;

	while (scuttle_dsc(stack, DSC_EMPTY, start))
		start = iter_dsc(start);
	hash = hash_stacks(stack);
	if (insert_hash(&result[hash % RESULT_SIZE], hash, start))
		return (1);
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		while (scuttle_dsc(stack, prev_dsc, current_dsc))
			current_dsc = iter_dsc(current_dsc);
		hash = hash_stacks(stack);
		if (insert_hash(&result[hash % RESULT_SIZE], hash, current_dsc))
			return (1);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(stack, prev_dsc, DSC_EMPTY);
	return (0);
}

int	test_rifle(t_stack *stack, t_uint depth, t_hashlist **result)
{
	t_uint	size;
	t_hash	hash;

	hash = hash_stacks(stack);
	if (insert_hash(&result[hash % RESULT_SIZE], hash, DSC_EMPTY))
		return (1);
	size = 1;
	while (size <= depth)
	{
		if (test_cycle(stack, mk_dsc(size), result))
			return (1);
		size++;
	}
	return (0);
}
