/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:01:56 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 01:37:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_dup(int old_fd)
{
	int			new_fd;
	t_cmd_info	*info;

	info = scan_info(NULL);
	new_fd = dup(old_fd);
	if (new_fd == -1)
		info->status = FAILURE;
	return (new_fd);
}

int	set_dup2(int og_fd, int copy_fd)
{
	int			new_fd;
	t_cmd_info	*info;

	info = scan_info(NULL);
	new_fd = dup2(og_fd, copy_fd);
	if (new_fd == -1)
	{
		info->status = FAILURE;
		return (FAILURE);
	}
	return (SUCCESS);
}