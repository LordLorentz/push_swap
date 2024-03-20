/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   titrate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 13:56:42 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/20 15:01:22 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ulong	hash_stacks(t_stack *a, t_stack *b);

t_stack	*fill_stack(t_uint size, t_uint start, t_uint end)
{
	t_stack *stack;
	
	stack = create_stack(16, start, end, end - start + 1);
}

int main(void)
{
	t_uint	i;
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(16, 0, 7);
	b = fill_stack(16, 8, 15);
	ft_printf("test\n");
}
