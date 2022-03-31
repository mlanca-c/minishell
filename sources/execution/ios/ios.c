/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ios.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:33:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 11:36:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function will store the 'original'
// FIXME:This troubles me because I dont see the sense of it
int	set_ios(t_cmd *command)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// info->io->reset_in = 1;
	// info->io->reset_out = 1;
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
	if (command->pipe == NO_PIPE)
	if (command->pipe && command->pipe != NO_PIPE)
		set_pipes(command);
	return (SUCCESS);
}

void	reset_ios(bool reset_in, bool reset_out)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (reset_in && info->io->in_safe)
	{
		safe_keeping(dup2(info->io->saved_stdin, STDIN_FILENO));
		if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
			safe_keeping(close(info->io->curr_in_fd));
		info->io->curr_in_fd = info->io->saved_stdin;
		info->io->saved_stdin = false;
	}
	if (reset_out && info->io->out_safe)
	{
		safe_keeping(dup2(info->io->saved_stdout, STDOUT_FILENO));
		if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
			safe_keeping(close(info->io->curr_out_fd));
		info->io->curr_out_fd = info->io->saved_stdout;
		info->io->saved_stdout = false;
	}
}

void	save_ios(int type)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->io->in_safe == false && type == IN)
	{
		info->io->saved_stdin = safe_keeping(dup(STDIN_FILENO));
		info->io->in_safe = true;
	}
	if (info->io->out_safe == false && type == OUT)
	{
		info->io->saved_stdout = safe_keeping(dup(STDOUT_FILENO));
		info->io->out_safe = true;
	}
}
