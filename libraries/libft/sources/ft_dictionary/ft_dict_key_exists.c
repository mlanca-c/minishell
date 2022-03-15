/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_key_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:40:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/15 20:40:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dict_key_exists(t_dict *dict, char *key)
{
	while (dict)
	{
		if (ft_strncmp(key, (char *)dict->key, ft_strlen(key)) == 0
			&& ft_strlen(key) == ft_strlen((char *)dict->key))
			return (1);
		dict = dict->next;
	}
	return (0);
}
