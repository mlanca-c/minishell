/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:57:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/26 14:32:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* ft_str_replace(char* source, char* sub, char* with)
{
	char* str;

	str = ft_strnstr(source, sub, ft_strlen(source));
	if (!str)
		return (NULL);
	ft_memmove(str + ft_strlen(with), str + ft_strlen(sub),
		ft_strlen(str) - ft_strlen(sub) + 1);
	ft_memcpy(str, with, ft_strlen(with));
	return (str + ft_strlen(with));
}
