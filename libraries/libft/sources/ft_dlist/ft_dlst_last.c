/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:48:49 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 20:57:36 by mlanca-c         ###   ########.fr       */
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
t_dlist	*ft_dlist_last(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
