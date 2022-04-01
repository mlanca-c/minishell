/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:39:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/12 13:39:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_dlist_size() function counts the number of elements in a dlist.
**
** @param	t_dlist	*dlist	- the beginning of the dlist.
**
** @return
** 		- The ft_dlist_size() function returns the number of elements in a dlist.
*/
int	ft_dlist_size(t_dlist *dlist)
{
	int	size;

	size = 0;
	while (dlist)
	{
		dlist = dlist->next;
		size++;
	}
	return (size);
}
