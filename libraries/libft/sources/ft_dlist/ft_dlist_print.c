/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:21:10 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/26 16:03:59 by mlanca-c         ###   ########.fr       */
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
void	ft_dlist_print(t_dlist *dlist)
{
	t_dlist	*temporary;

	if (!dlist)
		return ;
	temporary = dlist;
	while (temporary)
	{
		ft_putstr_fd(temporary->content, 1);
		if (temporary->next)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		temporary = temporary->next;
	}
}
