/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:15:02 by mmosk         #+#    #+#                 */
/*   Updated: 2024/05/03 17:19:53 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	const t_uint	size = argc - 1;
	t_uint			*temp;
	t_stack			*stack;
	t_uint			out;

	if (argc < 2)
		exit_wrapper();
	if (argc < 3)
		return (0);
	temp = read_stack(argv + 1, size);
	if (temp == NULL)
		exit_wrapper();
	stack = curse_stack(temp, size);
	free(temp);
	out = 0;
	// printf("head next %d\n head prev %d\n tail next %d\n tail prev %d\n",
	// 	stack->val[stack->head[A]].next,
	// 	stack->val[stack->head[A]].prev,
	// 	stack->val[stack->tail[A]].next,
	// 	stack->val[stack->tail[A]].prev);
	// print_stacks(stack);
	// scuttle_dsc(stack, DSC_EMPTY, 0xEE1);
	// print_stacks(stack);
	// printf("head next %d\n head prev %d\n tail next %d\n tail prev %d\n",
	// 	stack->val[stack->head[A]].next,
	// 	stack->val[stack->head[A]].prev,
	// 	stack->val[stack->tail[A]].next,
	// 	stack->val[stack->tail[A]].prev);
	// // scuttle_dsc(stack, 0xEE1, DSC_EMPTY);
	// // print_stacks(stack);
	// scuttle_dsc(stack, DSC_EMPTY, 0xA);
	// print_stacks(stack);
	// // scuttle_dsc(stack, 0xA2, DSC_EMPTY);
	// // print_stacks(stack);
	print_rifle(stack, 8);
	free_stack(stack);
	return (out);
}
