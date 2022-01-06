/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:18:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 11:23:52 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function adds an element to a list. 
** The ft_lstadd_front() function adds the element 'new' at the beginning of
** the list.
**
** @param	t_list 	**lst	- address of a pointer to the first link of a list.
** @param	t_list	*new	- address of a pointer to the element to be added to
** 							the list.
*/
void	ft_lst_add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
