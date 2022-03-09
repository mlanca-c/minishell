/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:15:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 21:41:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirs(t_cmd *command)
{
	t_redirs	has_redir;
	t_red		*redirs;
	t_list		*temp;
	//t_std_io	*std_io;

	has_redir.pipe_in = false;
	has_redir.pipe_out = false;
	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	while (temp)
	{
		redirs = (t_red *)command->redirection->content;
		if (!check_heredoc(redirs, &has_redir))
			return (FAILURE);
		// if else (!check_redir_files())
			// ..;
		// if else (!check_redir_pipes())
			// ..;
		temp = temp->next;
	}
	ft_lst_clear(temp, free);
	return (SUCCESS);
}

int	check_heredoc(t_red *redirs, t_redirs *has_redir)
{
	if (redirs->io_type == DLESS)
	{
		reset_origin_fd(has_redir);
		has_redir->pipe_in = true;
		if(!do_redir(redirs))
			return (FAILURE);
	}
	return (SUCCESS);
}
