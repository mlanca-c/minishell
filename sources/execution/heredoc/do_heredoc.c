/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:42:15 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 01:15:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_heredoc(t_red *redirs)
{
	char		*line;
	int			hd[2];
	t_std_io	*std_io;
	const int	limiter_len = ft_strlen(redirs->io_file) + 1;
	
	std_io = scan_std_io(NULL);
	save_std_in();
	if (set_pipe(hd) == FAILURE)
		return (FAILURE);
	line = readline("> ");
	while (line && ft_strncmp(redirs->io_file, line, limiter_len) != 0)
	{
		write(hd[WRITE], line, ft_strlen(line));
		write(hd[WRITE], "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	if (close(hd[WRITE]) == -1 || set_dup2(hd[READ], STDIN_FILENO) == -1)
	{
		perror("Something went wrong with heredoc\n");
		return (FAILURE);
	}
	set_curr_in_fd(std_io, hd[READ]);
	return (SUCCESS);
}