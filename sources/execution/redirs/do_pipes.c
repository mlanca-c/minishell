/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 16:22:40 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipes(int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (do_pipe(info->pipe_fd) == -1)
		return (FAILURE);
	if (info->has_infile == false)
	{
		if (info->og_fd->curr_in_fd != STDIN_FILENO)
			do_close(info->og_fd->curr_in_fd);
		do_dup2(info->pipe_fd[READ], STDIN_FILENO);
		info->og_fd->curr_in_fd = info->pipe_fd[READ];
	}
	if (info->has_outfile == false && index < info->lst_size - 1)
	{
		if (info->og_fd->curr_out_fd != STDOUT_FILENO)
			do_close(info->og_fd->curr_out_fd);
		do_dup2(info->pipe_fd[WRITE], STDOUT_FILENO);
		info->og_fd->curr_out_fd = info->pipe_fd[WRITE];
	}
	return (SUCCESS);
}

int	do_pipe(int fd[2])
{
	int			ret_fd;

	ret_fd = pipe(fd);
	if (ret_fd == -1)
	{
		perror("pipe Error\n");
		exit_shell();
	}
	return (ret_fd);
}

int	do_close(int fd)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
	{
		perror("close Error\n");
		exit_shell();
	}
	return (ret);
}