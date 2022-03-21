/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 01:49:04 by josantos          #+#    #+#             */
/*   Updated: 2022/03/20 16:17:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_ios(bool reset_in, bool reset_out)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (reset_in == 1)
		reset_is(info);
	if (reset_out == 1)
		reset_os(info);
	return (SUCCESS);
}

int	reset_is(t_cmd_info *info)
{
	if (info->io->in_safe == true)
	{
		do_dup2(info->io->saved_stdin, STDIN_FILENO);
		if (info->io->curr_in_fd != STDIN_FILENO
			&& info->io->curr_in_fd != -1)
			do_close(info->io->curr_in_fd);
		info->io->curr_in_fd = info->io->saved_stdin;
		info->io->in_safe = false;
	}
	return (SUCCESS);
}

int	reset_os(t_cmd_info *info)
{
	if (info->io->out_safe == true)
	{
		do_dup2(info->io->saved_stdout, STDOUT_FILENO);
		if (info->io->curr_out_fd != STDOUT_FILENO
			&& info->io->curr_out_fd != -1)
			do_close(info->io->curr_out_fd);
		info->io->curr_out_fd = info->io->saved_stdin;
		info->io->out_safe = false;
	}
	return (SUCCESS);
}
