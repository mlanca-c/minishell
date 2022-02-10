/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:13:07 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_delete(t_dict *dict, void (*del)(void *))
{
	if (!dict || !del)
		return ;
	(*del)(dict->key);
	(*del)(dict->content);
	free(dict);
}
