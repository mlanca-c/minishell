/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:07:51 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:41:58 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_print(t_dict *dict)
{
	t_dict	*temp;

	if (!dict)
		return ;
	temp = dict;
	while (temp)
	{
		printf("key: %s and content:%s", temp->key, temp->content);
		if (temp->next)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}
