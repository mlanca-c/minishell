/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:41:48 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 19:31:14 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(char *str)
{
	long long			a;
	long long			b;
	long long			c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if ((str[a] == '-') || (str[a] == '+'))
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = (c * 10) + (b * (str[a] - '0'));
		a++;
	}
	return (c);
}
