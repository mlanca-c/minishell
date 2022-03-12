/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:49:30 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 03:17:58 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	reset_og_fds(t_cmd_info *info)
{
	if ((info->has_infile == true || info->has_outfile == true) || info->lst_size > 1)
	{
		if (info->inside_pipe == false)
		{
			do_dup2(info->og_fd->saved_stdin, STDIN_FILENO);
			if (info->og_fd->curr_in_fd != STDIN_FILENO)
				do_close(info->og_fd->curr_in_fd);
			info->og_fd->curr_in_fd = info->og_fd->saved_stdin;
			info->og_fd->saved_stdin = 0;
		}
		do_dup2(info->og_fd->saved_stdout, STDOUT_FILENO);
		if (info->og_fd->curr_out_fd != STDOUT_FILENO)
			do_close(info->og_fd->curr_out_fd);
		info->og_fd->curr_out_fd = info->og_fd->saved_stdout;
		info->og_fd->saved_stdout = 0;
	}
	return (SUCCESS);
}*/