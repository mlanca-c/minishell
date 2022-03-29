/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:11:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 20:55:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_dlist_clear() function deletes and frees the given element and every
** successor of that element, using the function ’del’ and free(). Finally, the
** pointer to the list must be set to null.
**
** @param	t_dlist	**dlist		- address of a pointer to an element.
*/
void	ft_dlst_clear(t_dlist *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_dlst_clear(lst->next, del);
	ft_dlst_delete(lst, del);
}
