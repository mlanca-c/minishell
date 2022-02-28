/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:40:14 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 18:44:07 by josantos         ###   ########.fr       */
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
