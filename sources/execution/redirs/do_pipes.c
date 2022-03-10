/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:20:49 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipes(int index)
{
	t_cmd_info	*info;
	
	info = scan_info(NULL);
	if (pipe(info->fd) == -1)
		exit_shell();
	if (info->has_outfile == false && index < info->lst_size - 1)
		dup2(info->fd[1], STDOUT_FILENO);
	// if (info->has_infile == false && index != 0)
		// dup2(info->fd[0], STDIN_FILENO);
}