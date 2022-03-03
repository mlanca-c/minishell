/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:44:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/03 17:07:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function prints all data from a list.
** The ft_lstprint() function iterates the list, and prints with ft_putstr_fd()
** all the integers followed by a breakline.
**
** @param	t_stack	*stack	- stack to iterate from.
*/
void	ft_lst_print(t_list *lst, char *delimiter)
{
	while (lst)
	{
		if (lst->next)
			printf("%s%s", lst->content, delimiter);
		else
			printf("%s",lst->content);
		lst = lst->next;
	}
}
