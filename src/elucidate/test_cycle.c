/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_cycle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:56:37 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 15:28:50 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "elucidate.h"

int	test_cycle(t_stack *a, t_stack *b, t_dsc start, t_dpplist **result)
{
	t_dsc	current_dsc;
	t_dsc	prev_dsc;
	t_dpp	dpp;

	while (scuttle_dsc(a, b, DSC_EMPTY, start))
		start = iter_dsc(start);
	dpp = investigate(a, b, STACK_SIZE);
	if (insert_dpp(&result[dpp % RESULT_SIZE], dpp, start))
		return (1);
	prev_dsc = start;
	current_dsc = iter_dsc(prev_dsc);
	while (__builtin_expect(current_dsc != DSC_END, 1))
	{
		while (scuttle_dsc(a, b, prev_dsc, current_dsc))
			current_dsc = iter_dsc(current_dsc);
		dpp = investigate(a, b, STACK_SIZE);
		if (insert_dpp(&result[dpp % RESULT_SIZE], dpp, current_dsc))
			return (1);
		prev_dsc = current_dsc;
		current_dsc = iter_dsc(prev_dsc);
	}
	scuttle_dsc(a, b, prev_dsc, DSC_EMPTY);
	return (0);
}

int	test_rifle(t_stack *a, t_stack *b, t_uint depth, t_dpplist **result)
{
	t_uint	size;
	t_dpp	dpp;

	dpp = investigate(a, b, STACK_SIZE);
	if (insert_dpp(&result[dpp % RESULT_SIZE], dpp, DSC_EMPTY))
		return (1);
	size = 1;
	while (size <= depth)
	{
		if (test_cycle(a, b, mk_dsc(size), result))
			return (1);
		size++;
	}
	return (0);
}
