/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:53:27 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 16:09:15 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_heredoc(t_red *redir)
{
	t_cmd_info	*info;
	int			temp;
	char		*line;

	info = scan_info(NULL);
	info->heredoc_file = ft_strdup("heredoc.tmp");
	if (!info->heredoc_file)
		return (FAILURE);
	temp = open(info->heredoc_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (temp == -1)
		return (FAILURE);
	line = readline("> ");
	while (line && ft_strncmp(line, redir->io_file, ft_strlen(redir->io_file)))
	{
		write(temp, line, ft_strlen(line));
		write(temp, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	do_close(temp);
	return (SUCCESS);
}
