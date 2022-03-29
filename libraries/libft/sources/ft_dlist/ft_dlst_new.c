/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:47:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 20:58:32 by mlanca-c         ###   ########.fr       */
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
	t_dlist	*lst;

	lst = (t_dlist *)malloc(sizeof(t_dlist) * 1);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}
