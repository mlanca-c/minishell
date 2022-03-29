/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:21:10 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 20:59:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function prints all data from the dlist.
** The ft_dlist_print() function iterates the dlist, and prints with ft_putstr()
** all the strings followed by a semi-colon.
**
** @param	t_dlist	*dlist	- dlist to iterate from.
*/
void	ft_dlst_print(t_dlist *lst, char *delimiter)
{
	while (lst)
	{
		if (lst->next)
			printf("%s%s", (char *)lst->content, delimiter);
		else
			printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}
