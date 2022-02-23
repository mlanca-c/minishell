/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/02/23 10:20:17 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**free_dintpointer(int **pipe)
{
	size_t	i;

	i = 0;
	while (pipe[i])
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
	return (NULL);
}

void	exec_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	int	save_stdin;
	int	save_stdout;
	t_cmd	*command;

	command = (t_cmd *)cmd->content;
	save_stdin = dup(STDIN_FILENO);
	save_stdout = dup(STDOUT_FILENO);
	open_files(command, index, info);
	if (command->redirection || info->lst_size > 1)
		set_pipes(info->pipes, command);
}

void	execute_command_lst(t_list *cmd)
{
	t_cmd_info	*info;
	int			i;
	
	info = NULL;
	info = ft_calloc(1, sizeof(t_cmd_info *));
	if (!info)
		exit_shell();
	info->lst_size = ft_lst_size(cmd);
	info->pipes = init_pipes(info);
	i = 0;
	while (i < info->lst_size)
	{
		exec_cmd(cmd, info, i);
		cmd = cmd->next;
		i++;
	}
}
