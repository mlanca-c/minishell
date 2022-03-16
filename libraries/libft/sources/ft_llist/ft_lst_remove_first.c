/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:48:28 by josantos          #+#    #+#             */
/*   Updated: 2022/03/01 10:59:35 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_first(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	
	if (!lst || !*lst)
		return ;
	temp = *lst;
	temp = temp->next;
	del((*lst)->content);
	free(*lst);
	*lst = temp;
}