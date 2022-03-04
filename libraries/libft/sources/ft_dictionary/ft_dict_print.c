/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:07:51 by josantos          #+#    #+#             */
/*   Updated: 2022/03/03 16:36:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_print(t_dict *dict, char *message1, char *message2)
{
	t_dict	*temp;

	if (!dict)
		return ;
	temp = dict;
	while (temp)
	{
		if (!temp->content)
		{
			if (message2)
				printf(message2, (char *)temp->key);
		}
		else
			printf(message1, (char *)temp->key, (char *)temp->content);
		temp = temp->next;
	}
}
