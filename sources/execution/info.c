/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:22:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:30:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_io	*init_io(void);

t_cmd_info	*scan_info(t_dlist *command)
{
	static t_cmd_info	*info = NULL;

	if (!command)
		return (info);
	info = ft_calloc(1, sizeof(t_cmd_info));
	if (!info)
		exit_shell();
	info->io = init_io();
	info->lst_size = ft_dlst_size(command);
	info->status = 0;
	return (info);
}

void	free_info(t_cmd_info *info)
{
	free(info->io);
	if (info->heredoc_file)
		free(info->heredoc_file);
	free(info);
}

static t_io	*init_io(void)
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
