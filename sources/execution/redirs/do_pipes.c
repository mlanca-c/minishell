/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/03/29 20:37:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipes(t_cmd *command)
{
	if (command->pipe == PIPE_IN)
		return (set_pipe_in());
	else if (command->pipe == PIPE_OUT)
		return (set_pipe_out());
	else if (command->pipe == PIPE_IN_OUT)
		return (set_pipe_in_out());
	return (SUCCESS);
}

int	set_pipe_in(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
		do_close(info->io->curr_in_fd);
	do_pipe(info->pipe_fd);
	do_dup2(info->pipe_fd[READ], STDIN_FILENO);
	info->io->curr_in_fd = info->pipe_fd[READ];
	return (SUCCESS);
}

int	set_pipe_out(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
		do_close(info->io->curr_out_fd);
	do_dup2(info->pipe_fd[WRITE], STDOUT_FILENO);
	info->io->curr_out_fd = info->pipe_fd[WRITE];
	return (SUCCESS);
}

int	set_pipe_in_out(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
		do_close(info->io->curr_in_fd);
	if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
		do_close(info->io->curr_out_fd);
	do_dup2(info->pipe_fd[READ], STDIN_FILENO);
	info->io->curr_in_fd = info->pipe_fd[READ];
	do_pipe(info->pipe_fd);
	do_dup2(info->pipe_fd[WRITE], STDOUT_FILENO);
	info->io->curr_out_fd = info->pipe_fd[WRITE];
	return (SUCCESS);
}
