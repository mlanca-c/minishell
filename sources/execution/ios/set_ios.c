/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:05:41 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 18:47:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_ios(t_cmd *command, int index)
{
	bool	reset_in;
	bool	reset_out;
	
	reset_in = false;
	reset_out = false;
	check_save_ios(command, &reset_in, &reset_out);
	if (command->pipe && command->pipe != No_Pipe)
		set_pipes(command);
}

int	check_save_ios(t_cmd *command, bool reset_in, bool reset_out)
{
	if (command->pipe == Pipe_IN || command->redirection == Pipe_In_Out)
	{
		save_ios(IN);
		reset_in = true;
	}
	if (command->pipe == Pipe_OUT || command->redirection == Pipe_In_Out)
	{
		save_ios(OUT);
		reset_out = true;
	}
	return (SUCCESS);
}

void	save_ios(int type)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (type == IN)
	{
		info->io->saved_stdin = do_dup(STDIN_FILENO);
		info->io->save_in = true;
	}
	if (type == OUT)
	{
		info->io->saved_stdout = do_dup(STDOUT_FILENO);
		info->io->save_out = true;
	}
	
}