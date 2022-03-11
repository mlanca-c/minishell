/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:32:10 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 10:53:17 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_heredoc(t_cmd *command)
{
	char		*delimiter;
	t_red		*redir;
	t_list		*temp;
	t_cmd_info	*info;

	info = scan_info(NULL);
	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	while (temp)
	{
		redir = (t_red *)temp->content;
		if ((int)redir->io_type == DLESS)
			return(do_heredoc(redir));
	}
	return (SUCCESS);
}

int	do_heredoc(t_red *redir)
{
	char *line;

	while(true)
	{
		line = readline("> ");
		if (line == NULL);
		{
			free(line);
			break ;
		}
		if (!ft_strncmp())
	}
}