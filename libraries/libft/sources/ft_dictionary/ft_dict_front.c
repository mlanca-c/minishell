/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:32:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:58 by mlanca-c         ###   ########.fr       */
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
