/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:05:41 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 16:18:31 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_ios(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	info->io->reset_in = 1;
	info->io->reset_out = 1;
	check_save_ios(command);
	if (command->pipe && command->pipe != NO_PIPE)
		set_pipes(command);
	return (SUCCESS);
}

int	check_save_ios(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (command->pipe == PIPE_IN || command->pipe == PIPE_IN_OUT)
	{
		save_ios(IN);
		info->io->reset_in = 0;
	}
	if (command->pipe == PIPE_OUT || command->pipe == PIPE_IN_OUT)
	{
		save_ios(OUT);
		info->io->reset_out = 0;
	}
	return (SUCCESS);
}

int	save_ios(int type)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (type == IN && info->io->in_safe == false)
	{
		info->io->saved_stdin = do_dup(STDIN_FILENO);
		info->io->in_safe = true;
	}
	if (type == OUT && info->io->out_safe == false)
	{
		info->io->saved_stdout = do_dup(STDOUT_FILENO);
		info->io->out_safe = true;
	}
	return (SUCCESS);
}
