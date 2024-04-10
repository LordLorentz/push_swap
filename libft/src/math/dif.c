/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dif.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 17:03:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/08 17:06:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned int	dif(unsigned int a, unsigned int b)
{
	return (
		((a > b) * (a - b))
		+ ((a < b) * (b - a))
		);
}