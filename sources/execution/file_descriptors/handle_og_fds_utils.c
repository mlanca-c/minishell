/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_og_fds_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:20:17 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 01:24:54 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_curr_in_fd(t_std_io *std_io, int in_fd)
{
	if (std_io->curr_in != STDIN_FILENO)
		close(std_io->curr_in);
	std_io->curr_in = in_fd;
}

void	set_curr_out_fd(t_std_io *std_io, int out_fd)
{
	if (std_io->curr_out != STDOUT_FILENO)
		close(std_io->curr_out);
	std_io->curr_out = out_fd;
}

void	save_std_in(void)
{
	t_std_io	*std_io;

	std_io = scan_std_io(NULL);
	if (std_io->in_saved == false)
	{
		std_io->in_saved = set_dup(STDIN_FILENO);
		std_io->in_saved = true;
	}
}

void	save_std_out(void)
{
	t_std_io	*std_io;

	std_io = scan_std_io(NULL);
	if (std_io->out_saved == false)
	{
		std_io->out_saved = set_dup(STDOUT_FILENO);
		std_io->out_saved = true;
	}
}
