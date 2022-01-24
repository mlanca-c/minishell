/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:49:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/23 12:56:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfind(const char *s, char *find)
{
	int	i;
	int	j;

	if (!s || !find)
		return (-1);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == find[j])
		{
			j++;
		}
		if (!find[j])
			return (i);
		i++;
	}
	return (-1);
}
