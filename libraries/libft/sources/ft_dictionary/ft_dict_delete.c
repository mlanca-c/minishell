/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:13:07 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 13:51:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_delete(t_dict *dict, void (*del)(void *))
{
	if (!dict || !del)
		return ;
	(*del)(dict->key);
	if (dict->content)
		(*del)(dict->content);
	free(dict);
}
