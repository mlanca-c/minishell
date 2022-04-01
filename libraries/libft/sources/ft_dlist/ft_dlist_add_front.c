/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:08:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/26 16:04:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function adds an element to a list.
** The ft_dlist_add_front() function adds the element 'new' at the beginning of
** the dlist.
**
** @param	t_dlist **dlist	- address of a pointer to the first link of a
**							dlist.
** @param	t_dlist	*new	- address of a pointer to the element to be added
**							to the list.
*/
void	ft_dlist_add_front(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*temporary;

	temporary = *dlist;
	if (temporary)
	{
		new->next = temporary;
		temporary->previous = new;
	}
	*dlist = new;
}
