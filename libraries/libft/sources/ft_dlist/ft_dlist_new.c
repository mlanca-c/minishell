/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:47:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/12 13:44:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function creates a new element of a dlist.
** The ft_dlist_new() function allocates (with malloc()) and returns a new
** element.
** The variable 'data' is initialized with the value of the parameter
** 'data'. The variable 'next' is initialized to null, and so is the previous.
**
** @param	int	data	- data to create the new integer with.
**
** @return
** 		- The ft_dlist_new() function returns the new element of the dlist.
*/
t_dlist	*ft_dlist_new(void *content)
{
	t_dlist	*dlist;

	dlist = (t_dlist *)malloc(sizeof(t_dlist) * 1);
	if (!dlist)
		return (NULL);
	dlist->content = content;
	dlist->next = NULL;
	dlist->previous = NULL;
	return (dlist);
}
