/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:55:45 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_clear(t_dict *dict, void (*del)(void *))
{
	if (!dict)
		return ;
	ft_dict_clear(dict->next, del);
	ft_dict_delete(dict, del);
}
