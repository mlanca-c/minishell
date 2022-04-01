/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:22:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/01 01:03:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_io	*init_io(void);
static int	**init_pipe_fd(t_cmd_info *info);


t_cmd_info	*scan_info(t_dlist *command)
{
	static t_cmd_info	*info = NULL;

	if (!command)
		return (info);
	info = ft_calloc(1, sizeof(t_cmd_info));
	if (!info)
		exit_shell();
	info->lst_size = ft_dlst_size(command);
	info->pipe_fd = init_pipe_fd(info);
	info->io = init_io();
	info->status = 0;
	return (info);
}

static int	**init_pipe_fd(t_cmd_info *info)
{
	int	**pipes;
	int	i;

	if (info->lst_size == 1)
		return (0);
	pipes = ft_calloc(info->lst_size, sizeof(int *));
	if (!pipes)
		exit_shell();
	i = 0;
	while (i < info->lst_size - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
			exit_shell();
		safe_keeping(pipe(pipes[i]));
		i++;
	}
	return (pipes);
}

void	free_info(t_cmd_info *info)
{
	int	i;

	i = 0;
	free(info->io);
	if (info->pipe_fd)
	{
		while (info->pipe_fd[i])
			free(info->pipe_fd[i++]);
		free(info->pipe_fd);
	}
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
