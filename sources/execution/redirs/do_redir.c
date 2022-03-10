/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:34:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 03:03:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_redir(t_red *redirs)
{
	if (redirs->io_type == DLESS)
		return (do_heredoc(redirs));
	else if (redirs->io_type == GREAT || redirs->io_type == DGREAT)
		return (set_redir_out(redirs));
	else if (redirs->io_type == LESS)
		return (set_redir_in(redirs));
	else
		return (set_redir_pipe());
	return (FAILURE);
}

int	set_redir_out(t_red *redirs)
{
	t_std_io	*std_io;
	int			file_fd;
	t_cmd_info	*info;

	std_io = scan_std_io(NULL);
	info = scan_info(NULL);
	save_std_out();
	if (redirs->io_type == GREAT)
		file_fd = unlock_file(redirs->io_file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		file_fd = unlock_file(redirs->io_file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (file_fd == -1)
		return(FAILURE);
	set_curr_out_fd(std_io, file_fd);
	if (set_dup2(file_fd, STDOUT_FILENO) == FAILURE)
		return (FAILURE);
	info->has_outfile = true;
	return (SUCCESS);
}

int	set_redir_in(t_red *redirs)
{
	t_std_io	*std_io;
	int			file_fd;
	t_cmd_info	*info;

	std_io = scan_std_io(NULL);
	info = scan_info(NULL);
	save_std_in();
	file_fd = unlock_file(redirs->io_file, O_RDONLY, 0);
	if (file_fd == -1)
		return (FAILURE);
	set_curr_in_fd(std_io, file_fd);
	if (set_dup2(file_fd, STDIN_FILENO) == FAILURE)
		return (FAILURE);
	info->has_infile = true;
	return (SUCCESS);
}

int	set_redir_pipe(void)
{
	t_std_io	*std_io;
	int			fd[2];
	t_cmd_info	*info;

	info = scan_info(NULL);
	std_io = scan_std_io(NULL);
	if (info->index < info->lst_size - 1 && info->has_outfile == false)
	{
		save_std_out();
		if (set_pipe(fd) == FAILURE)
			return (FAILURE);
		set_curr_out_fd(std_io, fd[WRITE]);
		if (set_dup2(fd[READ], STDIN_FILENO) == FAILURE)
			return (FAILURE);
	}
	if (info->index != 0 && info->has_infile == false)
	{
		save_std_in();
		set_curr_in_fd(std_io, fd[READ]);
		if (set_dup2(fd[READ], STDIN_FILENO) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}