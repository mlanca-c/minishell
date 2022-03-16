/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:17:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/16 12:21:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dict_copy(t_dict *dict)
{
	t_dict	*new;

	if (!dict)
		return (NULL);
	new = NULL;
	while (dict)
	{
		if (!dict->content)
			ft_dict_add_back(&new, ft_dict_new(ft_strdup(dict->key), NULL));
		else
			ft_dict_add_back(&new, ft_dict_new(ft_strdup(dict->key),
					ft_strdup(dict->content)));
		dict = dict->next;
	}
	return (new);
}
