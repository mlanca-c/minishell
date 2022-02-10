/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:54:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_add_back(t_dict **dict, t_dict *new)
{
	t_dict	*last;

	if (!*dict)
		*dict = new;
	else
	{
		last = ft_dict_last(*dict);
		new->previous = last;
		last->next = new;
	}
}
