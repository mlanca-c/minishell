/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:19:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 21:13:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_info_type(t_dlist *lst);

void	init_info(t_dlist *lst, int std_fd[2])
{
	t_info	*info;
	t_dlist	*tmp;

	tmp = lst;
	while (tmp)
	{
		info = ft_calloc(1, sizeof(t_info));
		info->cur_fd[IN] = STDIN_FILENO;
		info->cur_fd[OUT] = STDOUT_FILENO;
		((t_cmd *)tmp->content)->info = info;
		tmp = tmp->next;
	}
	update_info_type(lst);
	file_descriptors(lst, std_fd);
}

static void	update_info_type(t_dlist *lst)
{
	int		i;
	int		size;
	t_info	*info;

	size = ft_dlst_size(lst);
	i = 1;
	while (lst)
	{
		info = ((t_cmd *)lst->content)->info;
		if (size == 1)
			info->type = NO_PIPE;
		else if (i == 1 && size > 1)
			info->type = PIPE_OUT;
		else if (i == size)
			info->type = PIPE_IN;
		else
			info->type = PIPE_IN_OUT;
		lst = lst->next;
		i++;
	}
}

// void	close_info_fd(t_dlist *lst, int std_fd[2])
// {
// }
