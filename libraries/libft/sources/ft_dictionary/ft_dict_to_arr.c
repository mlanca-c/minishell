/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:06:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/03 16:20:11 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	**ft_dict_to_arr(t_dict *dict, char *delimiter)
{
	char	**arr;
	char	*f;
	int		i;

	if (!dict)
		return (NULL);
	arr = ft_calloc(ft_dict_size(dict) + 1, sizeof(char *));
	i = 0;
	while (dict)
	{
		if (!delimiter)
		{
			arr[i] = ft_calloc(ft_strlen(dict->key) + ft_strlen(dict->content) + 1, sizeof(char));
			ft_strncat(arr[i], dict->key, ft_strlen(dict->key) + 1);
			ft_strncat(arr[i], dict->content, ft_strlen(dict->content) + 1);
			i++;
		}

			//arr[i++] = strjoin(dict->key, dict->content);
		else
		{
			f = ft_strjoin(dict->key, delimiter);
			arr[i++] = ft_strjoin(f, dict->content);
			free(f);
		}
		dict = dict->next;
	}
	arr[i] = NULL;
	return (arr);
}
