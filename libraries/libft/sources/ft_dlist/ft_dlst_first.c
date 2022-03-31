/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:44:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 11:40:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_dlist_last() funtion returns the last element of the dlist.
**
** @param	t_dlist	*dlist	- the beginning of the dlist.
**
** @return
** 		- the ft_dlist_last() funtion returns the last element of the dlist.
*/
t_dlist	*ft_dlst_first(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}
