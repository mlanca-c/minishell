/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:58:31 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 19:04:45 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_info	*scan_info(t_list *cmd)
{
	static t_cmd_info	*info = NULL;

	if (!cmd)
		return (info);
	info = (t_cmd_info *)ft_calloc(1, sizeof(t_cmd_info));
	if (!info)
		exit_shell();
	info->lst_size = ft_lst_size(cmd);
	info->io = init_io();
	info->has_infile = false;
	info->has_outfile = false;
	info->return_value = SUCCESS;
	info->inside_pipe = false;
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
	io->save_in = false;
	io->save_out = false;
	return (io);
}

void	free_info(t_cmd_info *info)
{
	free(info->io);
	free(info);
}