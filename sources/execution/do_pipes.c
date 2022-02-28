/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/02/28 15:00:14 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**init_pipes(t_cmd_info *info)
{
	int	**pipes;
	int	i;

	if (info->lst_size < 2)
		return (0);
	pipes = ft_calloc(info->lst_size, sizeof(int *));
	if (!pipes)
		exit_shell();
	i = 0;
	while (i < info->lst_size - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
		{
			free_dintpointer(pipes);
			exit_shell();
		}
		if (pipe(pipes[i]) == -1)
		{
			free_dintpointer(pipes);
			exit_shell();
		}
		i++;
	}
	return (pipes);
}

void	set_pipes(int **pipes, t_cmd *command, int index)
{
	t_red		*redirs;
	t_cmd_info	*info;

	info = scan_info(NULL);
	redirs = (t_red *)command->redirection;
	if (redirs)
	{
		if ((int)redirs->io_type != LESS && index != 0)
			dup2(pipes[index - 1][0], STDIN_FILENO);
		if (((int)redirs->io_type != GREAT || (int)redirs->io_type != DGREAT) && index != info->lst_size - 1)
			dup2(pipes[index][1], STDOUT_FILENO);
	}
}

int	open_files(t_cmd *command)
{
	int	in_fd;
	int	out_fd;
	t_red	*redir;

	in_fd = -13;
	out_fd = -13;
	while (command->redirection)
	{
		redir = (t_red *)command->redirection;
		if ((int)redir->io_type == LESS)
			in_fd = unlock_file(in_fd, redir, O_RDONLY, 0);
		if ((int)redir->io_type == GREAT)
			out_fd = unlock_file(out_fd, redir, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if ((int)redir->io_type == DGREAT)
			out_fd = unlock_file(out_fd, redir, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (in_fd == -1 || out_fd == -1)
			return (FAILURE);
		command->redirection = command->redirection->next;
	}
	return (SUCCESS);
}

int	unlock_file(int fd, t_red *redir, int flags, mode_t mode)
{
	int		new_fd;
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	if (fd != 13)
		close(fd);
	new_fd = open(redir->io_file, flags, mode);
	if (new_fd == -1)
	{
		printf("You managed to make Crash crash with %s -> %s\n", redir->io_file, strerror(errno));
		controllers->return_value = errno;
	}
	else
	{
		if (redir->io_type == LESS)
			dup2(new_fd, STDIN_FILENO);
		else if (redir->io_type == GREAT || redir->io_type == DGREAT)
			dup2(new_fd, STDOUT_FILENO);
	}
	return (new_fd);
}

void	close_pipes(t_cmd_info *info)
{
	int	i;

	i = 0;
	while (i < info->lst_size - 1)
	{
		close(info->pipes[i][0]);
		close(info->pipes[i][1]);
		i++;
	}
}