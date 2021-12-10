/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:31:09 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 18:02:50 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printnum(long long n)
{
	int	c;

	c = 0;
	if (n == 0)
	{
		c = 1;
		return (c);
	}
	if (n < 0)
		c++;
	while (n)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_llitoa(long long n)
{
	char	*p;
	int		b;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	b = printnum(n);
	p = (char *)malloc(sizeof(char) * (b + 1));
	if (p == 0)
		return (0);
	if (n == 0)
		p[0] = '0';
	p[b] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n != 0 && b >= 0)
	{
		p[b-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}
