/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_qchar.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 11:23:02 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/07 11:24:14 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
