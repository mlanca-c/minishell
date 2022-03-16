/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:27:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/09 18:24:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dict_replace(t_dict *dict, void *key, void *value)
{
	while (dict)
	{
		if (ft_strncmp(key, (char *)dict->key, ft_strlen(key)) == 0
			&& ft_strlen(key) == ft_strlen((char *)dict->key))
		{
			if (dict->content)
				free(dict->content);
			dict->content = value;
			return (dict->content);
		}
		dict = dict->next;
	}
	return (NULL);
}
