/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:58:48 by josantos          #+#    #+#             */
/*   Updated: 2022/03/15 18:12:07 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_redirs(t_cmd *command)
{
	t_list	*temp;
	t_red	*redir;

	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	while (temp)
	{
		redir = (t_red *)temp->content;
		if ((int)redir->io_type == LESS || (int)redir->io_type == DLESS)
		{
			if ((int)redir->io_type == DLESS && command->name
				&& ft_strncmp(command->name, "cat", 3))
				ft_lst_add_back(&command->suffix, ft_lst_new(ft_strdup("heredoc.tmp")));
			return (infile_process(redir));
		}
		if ((int)redir->io_type == GREAT || (int)redir->io_type == DGREAT)
			return (outfile_process(redir));
	}
	return (SUCCESS);
}

int	infile_process(t_red *redir)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	save_ios(IN);
	if (redir->io_type == LESS)
	{
		if (info->io->curr_in_fd != STDIN_FILENO)
			do_close(info->io->curr_in_fd);
		info->io->curr_in_fd = change_in(redir, STDIN_FILENO);
		info->io->reset_in = 0;
		if (info->io->curr_in_fd == -1)
			return (FAILURE);
		return (SUCCESS);
	}
	if (redir->io_type == DLESS)
	{
		if (setup_heredoc(redir) == FAILURE)
			return (FAILURE);
		if (info->io->curr_in_fd != STDIN_FILENO)
			do_close(info->io->curr_in_fd);
		info->io->curr_in_fd = change_in(redir, STDIN_FILENO);
		info->io->reset_in = 0;
	}
	return (SUCCESS);
}

int	outfile_process(t_red *redir)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	save_ios(OUT);
	do_close(info->io->curr_out_fd);
	info->io->curr_out_fd = change_out(redir, STDOUT_FILENO);
	info->io->reset_out = 0;
	if (info->io->curr_out_fd == -1)
		return (FAILURE);
	return (SUCCESS);
}
