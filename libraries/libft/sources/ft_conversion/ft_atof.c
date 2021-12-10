/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:49:29 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/02 15:22:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function converts a ASCII string to a floating point.
** The ft_atof() function converts the initial portion of the string pointed to
** by str to double representation.
**
** @param	const char	*str	- string to be converted to float.
**
** @return
** 		- The ft_atof() function returns the double representation of the string.
*/
double	ft_atof(char *str)
{
	double	number;
	int		negative;
	int		i;
	int		p;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	number = 0;
	while (ft_isdigit(str[i]))
		number = (number * 10) + (negative * (str[i++] - '0'));
	if (str[i++] == '.')
	{
		p = 0;
		while (ft_isdigit(str[i]) && p++)
			number = (number * 10) + (negative * (str[i++] - '0'));
		number = (number / ft_power(10, p));
	}
	return (number);
}
