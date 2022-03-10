/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:15:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 03:13:05 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirs(t_cmd *command)
{
	t_redirs	has_redir;
	t_red		*redirs;
	t_list		*temp;
	//t_std_io	*std_io;

	has_redir.in = false;
	has_redir.out = false;
	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	while (temp)
	{
		redirs = (t_red *)command->redirection->content;
		if (check_heredoc(redirs, &has_redir) == FAILURE)
			return (FAILURE);
		if (check_redir_files(redirs, &has_redir) == FAILURE)
			return (FAILURE);
		temp = temp->next;
	}
	if (check_redir_pipes(redirs, &has_redir) == FAILURE)
		return (FAILURE);
	ft_lst_clear(temp, free);
	reset_origin_fd(has_redir.out, has_redir.in);
	return (SUCCESS);
}

int	check_heredoc(t_red *redirs, t_redirs *has_redir)
{
	if (redirs->io_type == DLESS)
	{
		reset_origin_fd(has_redir->out, has_redir->in);
		has_redir->in = true;
		if(do_redir(redirs) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_redir_files(t_red *redirs, t_redirs *has_redirs)
{
	t_std_io	*std_io;

	std_io = scan_std_io(NULL);
	if (redirs->io_type == LESS)
		has_redirs->in = true;
	else
		has_redirs->out = true;
	if (do_redir(redirs) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_redir_pipes(t_red *redirs, t_redirs *has_redirs)
{
	t_std_io	*std_io;
	t_cmd_info	*info;

	std_io = scan_std_io(NULL);
	info = scan_info(NULL);
	if (info->index != 0 || info->index < info->lst_size - 1)
	{
		if (info->index != 0 && info->has_infile == false)
			has_redirs->in = true;
		else if (info->index < info->lst_size - 1 && info->has_outfile == false)
			has_redirs->out = true;
		if (do_redir(redirs) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
