/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:25:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/14 12:26:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_remove(t_dict **dict, void (*del)(void *))
{
	t_dict	*temporary;

	if (!dict)
		return ;
	temporary = *dict;
	if (temporary->next)
		temporary->next->previous = temporary->previous;
	if (temporary->previous)
		temporary->previous->next = temporary->next;
	if (temporary->previous)
		*dict = temporary->previous;
	else
		*dict = temporary->next;
	(*del)(temporary->key);
	if (temporary->content)
		(*del)(temporary->content);
	(*del)(temporary);
}
