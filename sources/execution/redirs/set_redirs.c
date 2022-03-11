/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:58:48 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 17:01:09 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_outfiles(t_cmd *command)
{
	t_red		*redir;
	t_list		*temp;
	t_cmd_info	*info;
	int			fd;

	info = scan_info(NULL);
	info->has_outfile = false;
	fd = -2;
	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	while (temp)
	{
		redir = (t_red *)temp->content;
		if ((int)redir->io_type == GREAT)
			fd = unlock_file(fd, redir, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if ((int)redir->io_type == DGREAT)
			fd = unlock_file(fd, redir, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (fd == -1)
			return (FAILURE);
		temp = temp->next;
	}
	ft_lst_clear(temp, free);
	if (check_dup(fd, OUT) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	check_infiles(t_cmd *command)
{
	t_red		*redir;
	t_list		*temp;
	t_cmd_info	*info;
	int			fd;

	info = scan_info(NULL);
	info->has_infile = false;
	temp = t_red_copy(command->redirection, ft_lst_size(command->redirection));
	fd = -2;
	while (temp)
	{
		redir = (t_red *)temp->content;
		if ((int)redir->io_type == LESS)
			fd = unlock_file(fd, redir, O_RDONLY, 0);
		if (fd == -1)
			return (FAILURE);
		temp = temp->next;
	}
	ft_lst_clear(temp, free);
	if (check_dup(fd, IN) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	check_dup(int fd, int type)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (fd != -2)
	{
		if (type == IN)
		{
			if (do_dup2(fd, STDIN_FILENO) == -1)
				return (info->return_value);
			info->has_infile = true;
			info->og_fd->curr_in_fd = fd;
		}
		else
		{
			if (do_dup2(fd, STDOUT_FILENO) == -1)
				return (info->return_value);
			info->has_outfile = true;
			info->og_fd->curr_out_fd = fd;
		}
	}
	return (SUCCESS);
}

int	unlock_file(int fd, t_red *redir, int flags, mode_t mode)
{
	int		new_fd;
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	if (fd != -2)
		close(fd);
	new_fd = open(redir->io_file, flags, mode);
	if (new_fd == -1)
	{
		open_err(redir->io_file, strerror(errno));
		controllers->return_value = errno;
	}
	return (new_fd);
}
