/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_scanners_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:32:11 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 22:35:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*t_red_copy(t_list *origin, int end)
{
	int		i;
	t_red	*node;
	t_list	*list;

	list = NULL;
	if (!origin)
		return (NULL);
	if (end > ft_lst_size(origin))
		end = ft_lst_size(origin);
	i = 0;
	node = NULL;
	while (origin)
	{
		node = ft_calloc(1, sizeof(t_red));
		node->io_file = ft_strdup(((t_red *)origin->content)->io_file);
		node->io_type = ((t_red *)origin->content)->io_type;
		ft_lst_add_back(&list, ft_lst_new(node));
		origin = origin->next;
		i++;
		if (i == end)
			return (list);
	}
	return (list);
}
