/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:34:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 01:19:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_redir(t_red *redirs)
{
	if (redirs->io_type == DLESS)
		return (do_heredoc(redirs));
	else if (redirs->io_type == GREAT || DGREAT)
		return (set_redir_out(redirs));
	else if (redirs->io_type == LESS)
		return (set_redir_in(redirs));
	else
		return (set_redir_pipe(redirs));
	return (SUCCESS);
}

int	set_redir_out(t_red *redirs)
{
	t_std_io	*std_io;
	int			file_fd;

	std_io = scan_std_io(NULL);
	save_std_out();
	if (redirs->io_type == GREAT)
		file_fd = unlock_file(redirs->io_file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		file_fd = unlock_file(redirs->io_file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (file_fd == -1)
		return(FAILURE);
	set_curr_out_fd(std_io, )
}