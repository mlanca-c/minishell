/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:14:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/12 13:17:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function duplicates a dlist.
** The ft_dlist_duplicate() function copies a dlist 'dlist' and creates a
** duplicate of that dlist 'duplicate'.
*/
t_dlist	*ft_dlist_duplicate(t_dlist *dlist)
{
	t_dlist	*duplicate;
	t_dlist	*new_node;

	duplicate = 0;
	while (dlist)
	{
		new_node = ft_dlist_new(dlist->content);
		if (!new_node)
		{
			ft_dlist_clear(&duplicate);
			return (0);
		}
		ft_dlist_add_back(&duplicate, new_node);
		dlist = dlist->next;
	}
	return (duplicate);
}
