/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distillate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 12:04:54 by mmosk         #+#    #+#                 */
/*   Updated: 2024/03/18 14:02:44 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Algorithms:
//--RB can only be followed by RRA if A has not yet been rotated in the current
//		associative plane.
//--__Same for the inverse operations.
//--SA requires an operation that modifies stack A before it can be repeated.