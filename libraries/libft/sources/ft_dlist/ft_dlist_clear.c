/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:11:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/09 11:59:22 by josantos         ###   ########.fr       */
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
void	ft_dlist_clear(t_dlist **dlist)
{
	if (!dlist)
		return ;
	while (*dlist)
		ft_dlist_remove(dlist);
}
