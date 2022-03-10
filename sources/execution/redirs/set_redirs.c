/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:15:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 00:45:57 by josantos         ###   ########.fr       */
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
		else if (check_redir_files(redirs, &has_redir) == FAILURE)
			return (FAILURE);
		// if else (!check_redir_pipes())
			// ..;
		temp = temp->next;
	}
	ft_lst_clear(temp, free);
	reset_origin_fd(redirs);
	return (SUCCESS);
}

int	check_heredoc(t_red *redirs, t_redirs *has_redir)
{
	if (redirs->io_type == DLESS)
	{
		reset_origin_fd(has_redir);
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
		has_redirs->in;
	else
		has_redirs->out;
	if (do_redir(std_io, redirs) == FAILURE);
		return (FAILURE);
	return (SUCCESS);
}
