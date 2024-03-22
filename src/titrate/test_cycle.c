/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_cycle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:56:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/22 18:04:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "titrate.h"

int	test_cycle(t_stack *a, t_stack *b, t_dsc start, t_hashlist **result)
{
	t_dsc	current_dsc;
	t_dsc	prev_dsc;
	t_hash	hash;

	while (scuttle_dsc(a, b, DSC_EMPTY, start))
		start = iter_dsc(start);
	hash = hash_stacks(a, b);
	if (insert_hash(&result[hash % RESULT_SIZE], hash, start))
		return (1);
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		while (scuttle_dsc(a, b, prev_dsc, current_dsc))//might reach DSC_END
			current_dsc = iter_dsc(current_dsc);
		hash = hash_stacks(a, b);
		if (insert_hash(&result[hash % RESULT_SIZE], hash, current_dsc))
			return (1);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, prev_dsc, DSC_EMPTY);
	return (0);
}

int	test_rifle(t_stack *a, t_stack *b, t_uint depth, t_hashlist **result)
{
	t_uint	size;

	size = 1;
	while (size <= depth)
	{
		if (run_titrate(a, b, mk_dsc(size), result))
		{
			free_hashlist_arr(result, RESULT_SIZE);
			free_stack(a);
			free_stack(b);
			return (1);
		}
		size++;
	}
	return (0);
}
