/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:41:31 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 12:16:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	infile_process(t_red *redirection);
static int	outfile_process(t_red *redirection);
static int	change_io(t_red *redirection, int io);
static int	get_fd(t_red *redirection);

int	do_redirs(t_cmd *command)
{
	t_dlist	*lst;
	t_red	*redirection;
	int		status;

	lst = t_red_copy(command->redirection, ft_dlst_size(command->redirection));
	status = SUCCESS;
	while (lst)
	{
		redirection = (t_red *)lst->content;
		// HERE_DOC
		if (redirection->io_type == LESS)
			status = infile_process(redirection);
		else if (redirection->io_type == GREAT
			|| redirection->io_type == DGREAT)
			status = outfile_process(redirection);
		if (status == FAILURE)
			break ;
		lst = lst->next;
	}
	ft_dlst_clear(ft_dlst_first(lst), free_redirection);
	return (status);
}

static int	infile_process(t_red *redirection)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	save_ios(IN);
	if (redirection->io_type == LESS)
	{
		if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
			safe_keeping(close(info->io->curr_in_fd));
		info->io->curr_in_fd = change_io(redirection, IN);
		info->io->reset_in = 0;
		if (info->io->curr_in_fd == -1)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	outfile_process(t_red *redirection)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	save_ios(OUT);
	if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
		safe_keeping(close(info->io->curr_out_fd));
	info->io->curr_out_fd = change_io(redirection, OUT);
	info->io->reset_out = 0;
	if (info->io->curr_out_fd == -1)
		return (FAILURE);
	return (SUCCESS);
}

static int	change_io(t_red *redirection, int io)
{
	t_cmd_info	*info;
	int			fd;

	info = scan_info(NULL);
	fd = get_fd(redirection);
	if (fd == -1)
		return (-1);
	if (io == IN)
		safe_keeping(dup2(fd, STDIN_FILENO));
	else if (io == OUT)
		safe_keeping(dup2(fd, STDOUT_FILENO));
	return (fd);
}

static int	get_fd(t_red *redirection)
{
	char	*file;

	file = redirection->io_file;
	if (redirection->io_type == LESS)
	{
		if (open(file, F_OK) == -1)
		{
			ft_putstr_fd(SHELL " ", STDERR_FILENO);
			ft_putstr_fd(redirection->io_file, STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
			return (-1);
		}
		return (open(file, O_RDONLY));
	}
	else if (redirection->io_type == GREAT)
		return (open(file, O_RDONLY | O_CREAT | O_TRUNC, 0666));
	return (open(file, O_RDONLY | O_CREAT | O_APPEND, 0666));
}
