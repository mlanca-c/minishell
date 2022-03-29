/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:58:31 by josantos          #+#    #+#             */
/*   Updated: 2022/03/29 20:24:33 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_info	*scan_info(t_dlist *cmd)
{
	static t_cmd_info	*info = NULL;

	if (!cmd)
		return (info);
	info = (t_cmd_info *)ft_calloc(1, sizeof(t_cmd_info));
	if (!info)
		exit_shell();
	info->lst_size = ft_dlist_size(cmd);
	info->io = init_io();
	info->return_value = SUCCESS;
	info->status = 0;
	return (info);
}

t_io	*init_io(void)
{
	t_io	*io;

	io = ft_calloc(1, sizeof(t_io));
	io->curr_in_fd = STDIN_FILENO;
	io->curr_out_fd = STDOUT_FILENO;
	io->saved_stdin = -2;
	io->saved_stdout = -2;
	io->in_safe = false;
	io->out_safe = false;
	io->reset_in = 1;
	io->reset_out = 1;
	return (io);
}

void	free_info(t_cmd_info *info)
{
	free(info->io);
	free(info->heredoc_file);
	free(info);
}
