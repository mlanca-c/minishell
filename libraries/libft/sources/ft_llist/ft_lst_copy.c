/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:01:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/04 10:52:10 by josantos         ###   ########.fr       */
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
		ft_lst_add_back(&list, ft_lst_new(ft_strdup(origin->content)));
		origin = origin->next;
		i++;
		if (i == end)
			return (list);
	}
	return (list);
}
