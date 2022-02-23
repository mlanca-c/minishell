/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:07:12 by josantos          #+#    #+#             */
/*   Updated: 2022/02/23 17:07:53 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dict_size(t_dict *dict)
{
	int	size;

	size = 0;
	while (dict)
	{
		dict = dict->next;
		size++;
	}
	return (size);
}