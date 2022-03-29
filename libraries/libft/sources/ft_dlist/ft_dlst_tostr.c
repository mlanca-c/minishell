/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_tostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:12:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:12:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dlst_tostr(t_dlist *list, char *delimiter)
{
	char	*str;
	char	*f;

	if (!delimiter || !list)
		return (NULL);
	str = NULL;
	while (list)
	{
		if (!str)
			str = ft_strdup((char *)list->content);
		else
		{
			f = str;
			str = ft_strjoin(str, delimiter);
			free(f);
			f = str;
			str = ft_strjoin(str, (char *)list->content);
			free(f);
		}
		list = list->next;
	}
	return (str);
}
