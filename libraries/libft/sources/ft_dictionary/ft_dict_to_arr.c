/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:06:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/02 12:16:52 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dict_to_arr(t_dict *dict, char *delimiter)
{
	char	**arr;
	char	*f;
	int		i;

	if (!dict)
		return (NULL);
	arr = ft_calloc(ft_dict_size(dict), sizeof(char *));
	i = 0;
	while (dict)
	{
		if (!delimiter)
			arr[i++] = ft_strjoin(dict->key, dict->content);
		else
		{
			f = ft_strjoin(dict->key, delimiter);
			arr[i++] = ft_strjoin(f, dict->content);
			free(f);
		}
		dict = dict->next;
	}
	return (arr);
}
