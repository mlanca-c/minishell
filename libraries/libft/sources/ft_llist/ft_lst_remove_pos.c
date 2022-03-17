/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:37:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/16 19:47:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** The ft_lstdelone() function takes as a parameter an element and frees the
** memory of the element’s content using the function ’del’ given as a parameter
** and free the element. The memory of ’next’ must not be freed.
**
** @param	t_list	*lst		- the element to free.
** @param	void (*del)(void *)	- the address of the function used to delete the
** 								content.
*/
void	ft_lst_remove_pos(t_list **lst, void (*del)(void *), int pos)
{
	t_list	*temporary;
	int		i;

	if (!lst)
		return ;
	temporary = *lst;
	i = 0;
	while (temporary)
	{
		if (i == pos)
		{
			*lst = temporary->next;
			temporary->next = NULL;
			(*del)(temporary->content);
			free(temporary);
			return ;
		}
		temporary = temporary->next;
	}
}
