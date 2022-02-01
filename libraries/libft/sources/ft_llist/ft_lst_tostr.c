/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:54:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 21:06:33 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lst_tostr(t_list *list, char *delimiter)
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
