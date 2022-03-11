/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 19:14:19 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipes(t_cmd *command)
{
	if (command->pipe == Pipe_IN)
		return(set_pipe_in(command));
	else if (command->pipe == Pipe_OUT)
		return (set_pipe_out(command));
	else if (command->pipe == Pipe_In_Out)
		return (set_pipe_in_out(command));
	return (SUCCESS);
	
	/*t_cmd_info	*info;

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
	return (SUCCESS);*/
}

int	set_pipe_in(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_in_fd != STDIN_FILENO)
		do_close(info->io->curr_in_fd);
	do_dup2(info->pipe_fd[READ], STDIN_FILENO);
	info->io->curr_in_fd = info->pipe_fd[0];
	return (SUCCESS);
}

int	set_pipe_out(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_out_fd != STDOUT_FILENO)
		do_close(info->io->curr_out_fd);
	do_pipe(info->pipe_fd);
	do_dup2(info->pipe_fd[WRITE], STDOUT_FILENO);
	info->io->curr_out_fd = info->pipe_fd[WRITE];
	return (SUCCESS);
}

int	set_pipe_in_out(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->curr_in_fd != STDIN_FILENO)
		do_close(info->io->curr_in_fd);
		if (info->io->curr_out_fd != STDOUT_FILENO)
		do_close(info->io->curr_out_fd);
	do_dup2(info->pipe_fd[READ], STDIN_FILENO);
	info->io->curr_in_fd = info->pipe_fd[0];
	do_dup2(info->pipe_fd[WRITE], STDOUT_FILENO);
	info->io->curr_out_fd = info->pipe_fd[WRITE];
	return (SUCCESS);
}
