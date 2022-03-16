/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:08:34 by josantos          #+#    #+#             */
/*   Updated: 2022/03/16 14:40:11 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_in(t_red	*redir, int old_fd)
{
	int			in;
	t_cmd_info	*info;

	info = scan_info(NULL);
	in = get_fd(redir, info);
	if (in == -1)
		return (-1);
	do_dup2(in, old_fd);
	return (in);
}

int	change_out(t_red *redir, int old_fd)
{
	int			out;
	t_cmd_info	*info;

	info = scan_info(NULL);
	out = get_fd(redir, info);
	if (out == -1)
		return (-1);
	do_dup2(out, old_fd);
	return (out);
}

int	get_fd(t_red *redir, t_cmd_info *info)
{
	char	*file;

	if (redir->io_type == LESS || redir->io_type == DLESS)
	{
		if (redir->io_type == LESS)
			file = redir->io_file;
		else
			file = info->heredoc_file;
		if (open(file, F_OK) == -1)
		{
			ft_putstr_fd("crash-1.0$ ", STDERR_FILENO);
			ft_putstr_fd(redir->io_file, STDERR_FILENO);
			ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
			return (-1);
		}
		return (open(file, O_RDONLY, 0));
	}
	else if (redir->io_type == GREAT)
		return (open(redir->io_file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else
		return (open(redir->io_file, O_RDWR | O_CREAT | O_APPEND, 0666));
}
