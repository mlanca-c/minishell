/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:58:09 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/09 23:48:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_abs() function computes the absolute value of the integer argument j.
**
** @param	int	j	- integer to be computed.
**
** @return
** 		- The ft_abs() function returns the absolute value of the integer
** 		argument.
*/
int	ft_abs(int j)
{
	if (j < 0)
		return (-j);
	return (j);
}
