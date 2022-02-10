/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:23:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 12:20:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dict_find(t_dict *dict, void *key)
{
	while (dict)
	{
		if (ft_strncmp(key, (char *)dict->key, ft_strlen(key)) == 0
			&& ft_strlen(key) == ft_strlen((char *)dict->key))
			return (dict->content);
		dict = dict->next;
	}
	return (NULL);
}
