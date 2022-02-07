/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:43:10 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 11:48:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dict_new(void *key, void *content)
{
	t_dict	*dict;

	dict = (t_dict *)ft_calloc(1, sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->key = key;
	dict->content = content;
	dict->next = NULL;
	dict->previous = NULL;
	return (dict);
}
