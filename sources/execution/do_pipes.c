/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 20:49:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	**init_pipes(t_cmd_info *info)
{
	int	**pipes;
	int	i;

	if (info->lst_size < 2)
		return (0);
	pipes = ft_calloc(info->lst_size, sizeof(int *));
	if (!pipes)
		exit_shell(MALLOC);
	i = 0;
	while (i < info->lst_size - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
		{
			ft_free_dintpointer(pipes);
			exit_shell(MALLOC);
		}
		if (pipe(pipes[i]) == -1)
		{
			ft_free_dintpointer(pipes);
			exit_shell(PIPE);
		}
		i++;
	}
	return (pipes);
}*/

/*void	set_redirs(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (info->in_fd)
		dup2(info->in_fd, STDIN_FILENO);
	if (info->out_fd)
		dup2(info->out_fd, STDOUT_FILENO);
		
}*/

int	has_redir(t_cmd *command, int type)
{
	t_red	*redirs;
	t_cmd	*temp;
	bool	checker;
	
	checker = false;
	if (!command->redirection)
		return (checker);
	else
	{
		temp = command;
		while (temp->redirection)
		{
			redirs = (t_red *)command->redirection->content;
			if ((int)redirs->io_type == type)
			{
				checker = true;
				break ;
			}
			temp->redirection = temp->redirection->next;
		}
	}
	return (checker);
}

/*void	set_pipes(int **pipes, t_cmd *command, int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// if (command->redirection)
		// set_redirs();
	if (!has_redir(command, LESS) && index != 0)
		dup2(pipes[index - 1][0], STDIN_FILENO);
	if (!has_redir(command, GREAT) && !has_redir(command, DGREAT)
		&& index != info->lst_size - 1)
		dup2(pipes[index][1], STDOUT_FILENO);
}*/

/*int	check_outfiles(t_cmd *command)
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
	if (fd != -2)
	{
		dup2(fd, STDOUT_FILENO);
		info->has_outfile = true;
	}
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
	if (fd != -2)
	{
		dup2(fd, STDIN_FILENO);
		info->has_infile = true;
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
		printf("crash-1.0$ %s: %s\n", redir->io_file, strerror(errno));
		controllers->return_value = errno;
	}
	return (new_fd);
}
	
void	close_pipes(t_cmd_info *info)
{
	int	i;

	i = 0;
	while (i < info->lst_size - 1)
	{
		close(info->pipes[i][0]);
		close(info->pipes[i][1]);
		i++;
	}
}*/