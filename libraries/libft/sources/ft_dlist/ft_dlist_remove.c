/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:38:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 20:23:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_dlist_remove() function takes as a parameter an element and frees the
** memory of the element’s content making its previous element point to it's
** next and its next point to its previous; it also frees the element.
**
** @param	t_dlist	*dlist		- the element to remove.
*/
void	ft_dlist_remove(t_dlist *dlist, void (*del)(void *))
{
	t_dlist	*temporary;

	if (!dlist)
		return ;
	temporary = dlist;
	if (temporary->next)
		temporary->next->previous = temporary->previous;
	if (temporary->previous)
		temporary->previous->next = temporary->next;
	if (temporary->previous)
		dlist = temporary->previous;
	else
		dlist = temporary->next;
	del(temporary);
}
