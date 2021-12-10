/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:25:57 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 18:04:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *str)
{
	int	a;
	int	b;

	if (ft_strlen(str) < 1)
		return (0);
	a = 0;
	while (str[a])
	{
		if (!(str[a] >= '0' && str[a] <= '9')
			&& !(str[a] >= 'a' && str[a] <= 'z')
			&& !(str[a] >= 'A' && str[a] <= 'Z'))
			return (0);
		b = a + 1;
		while (str[b])
		{
			if (str[a] == str[b])
				return (0);
			b++;
		}
		a++;
	}
	return (a);
}

static int	get_len(unsigned long long n, int b)
{
	int	a;

	a = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= b;
		a++;
	}
	return (a);
}

char	*ft_llitoa_base(unsigned long long n, char *base)
{
	int		b;
	int		len;
	char	*p;

	b = check_base(base);
	if (!b)
		return (NULL);
	len = get_len(n, b);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n == 0)
	{
		p[0] = base[0];
		return (p);
	}
	while (len > 0)
	{
		p[--len] = base[n % b];
		n /= b;
	}
	return (p);
}
