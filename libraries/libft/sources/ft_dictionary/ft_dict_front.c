/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:32:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 09:35:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dict_front(t_dict *dict)
{
	if (!dict)
		return (NULL);
	while (dict->previous)
		dict = dict->previous;
	return (dict);
}