/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:07:51 by josantos          #+#    #+#             */
/*   Updated: 2022/03/16 11:29:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_print(t_dict *dict, char *message1, char *message2)
{
	t_dict	*temp;
	char	*key;
	char	*value;

	if (!dict)
		return ;
	temp = dict;
	while (temp)
	{
		key = temp->key;
		value = temp->content;
		if (!value)
		{
			if (message2)
				printf(message2, (char *)key);
		}
		else if (!value[0])
			printf(message1, (char *)key, "");
		else
			printf(message1, (char *)key, (char *)value);
		temp = temp->next;
	}
}
