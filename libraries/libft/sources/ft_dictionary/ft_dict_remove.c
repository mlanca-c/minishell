/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:03:57 by josantos          #+#    #+#             */
/*   Updated: 2022/02/09 12:07:47 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_remove(t_dict **dict)
{
	t_dict	*temp;
	
	if (!dict)
		return ;
	temp = *dict;
	if (temp->next)
		temp->next->previous = temp->previous;
	if (temp->previous)
		temp->previous->next = temp->next;
	if (temp->previous)
		*dict = temp->previous;
	else
		*dict = temp->next;
	free(temp);
	
}