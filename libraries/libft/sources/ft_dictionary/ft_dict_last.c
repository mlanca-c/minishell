/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:59:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 12:00:37 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dict_last(t_dict *dict)
{
	if (!dict)
		return (NULL);
	while (dict->next)
		dict = dict->next;
	return (dict);
}