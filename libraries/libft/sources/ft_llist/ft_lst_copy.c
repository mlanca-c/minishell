/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:01:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 11:14:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_copy(t_list *origin, int end)
{
	int		i;
	t_list	*list;

	if (!origin)
		return (NULL);
	if (end > ft_lst_size(origin))
		end = ft_lst_size(origin);
	i = 0;
	list = NULL;
	while (origin)
	{
		ft_lst_add_back(&list, ft_lst_new(origin->content));
		origin = origin->next;
		i++;
		if (i == end)
			return (list);
	}
	return (list);
}
