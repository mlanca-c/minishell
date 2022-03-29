/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:05:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:06:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlst_copy(t_dlist *origin, int end)
{
	int		i;
	t_dlist	*lst;

	if (!origin)
		return (NULL);
	if (end > ft_dlst_size(origin))
		end = ft_dlst_size(origin);
	i = 0;
	lst = NULL;
	while (origin)
	{
		ft_dlst_add_back(&lst, ft_dlst_new(ft_strdup(origin->content)));
		origin = origin->next;
		i++;
		if (i == end)
			return (lst);
	}
	return (lst);
}
