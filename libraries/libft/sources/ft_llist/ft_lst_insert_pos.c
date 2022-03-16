/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:58:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/16 19:12:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_insert_pos(t_list **lst, t_list *insert, int pos)
{
	t_list *temp;
	t_list *old;
	int		i;

	if (pos < 0 || pos > ft_lst_size(*lst))
		return ;
	temp = *lst;
	i = 0;
	while (temp)
	{
		if (i == pos)
		{
			old = temp->next;
			temp->next = insert;
			insert = ft_lst_last(insert);
			insert->next = old;
			return ;
		}
		i++;
		temp = temp->next;
	}
	*lst = temp;
}
