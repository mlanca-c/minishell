/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:26:11 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 18:30:54 by mlanca-c         ###   ########.fr       */
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
