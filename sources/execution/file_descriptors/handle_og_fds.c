/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_og_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:50:19 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 21:30:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	save_origin_fds(void)
{
	t_std_io	*std_io;

	std_io = NULL;
	std_io = scan_std_io(GET);
	if (std_io->in_saved == false)
	{
		std_io->std_in = set_dup(STDIN_FILENO);
		if (std_io->std_in == -1)
			exit_shell_message(DUP);
		std_io->in_saved = true;
	}
	if (std_io->out_saved == false)
	{
		std_io->std_out = set_dup(STDOUT_FILENO);
		if (std_io->std_out  == -1)
			exit_shell_message(DUP);
		std_io->out_saved = true;
	}
	return (SUCCESS);
}

void	reset_origin_fd(t_redirs *has_redirs)
{
	if (has_redirs->pipe_in == false)
		reset_origin_in_fd();
	if (has_redirs->pipe_in == false)
		reset_origin_out_fd();
}

void	reset_origin_in_fd(void)
{
	t_std_io	*std_io;

	std_io = scan_std_io(NULL);
	if (std_io->in_saved == true)
	{
		if (set_dup2(std_io->std_in, STDIN_FILENO) == -1)
			exit_shell_message(DUP);
		std_io->in_saved = false;
		get_curr_in_fd(std_io);
	}
}

void	reset_origin_out_fd(void)
{
	t_std_io	*std_io;

	std_io = scan_std_io(NULL);
	if (std_io->out_saved == true)
	{
		if (set_dup2(std_io->std_out, STDOUT_FILENO) == -1)
			exit_shell_message(DUP);
		std_io->out_saved = false;
		get_curr_out_fd(std_io);
	}
}