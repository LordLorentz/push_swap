/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 17:01:14 by mmosk         #+#    #+#                 */
/*   Updated: 2024/04/12 12:46:44 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

// in < size
unsigned int wrap(unsigned int in, unsigned int size)
{
	return (
		(in <= (size / 2)) * in
		+ (in > (size / 2)) * (size - in)
		);
}
