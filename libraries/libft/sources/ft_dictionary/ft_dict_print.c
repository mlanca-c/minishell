/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:07:51 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:52:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_print(t_dict *dict, char *message)
{
	t_dict	*temp;

	if (!dict)
		return ;
	temp = dict;
	while (temp)
	{
		printf(message, (char *)temp->key, (char *)temp->content);
		temp = temp->next;
	}
}
