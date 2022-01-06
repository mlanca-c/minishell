/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:15:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 12:00:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*/
char	*ft_strjoinc(char *s, char c)
{
	char	*str;
	int		i;

	if (!c)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	if (s)
		free(s);
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
