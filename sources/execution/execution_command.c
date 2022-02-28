/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/02/28 15:43:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	int		save_stdin;
	int		save_stdout;
	t_cmd	*command;
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	command = (t_cmd *)cmd->content;
	save_stdin = dup(STDIN_FILENO);
	save_stdout = dup(STDOUT_FILENO);
	open_files(command);
	if (controllers->return_value == SUCCESS)
		set_pipes(info->pipes, command, index);
	/*if (is_builtin(command))
		exec_builtin(command);
	else*/
		exec_program(command);
	dup2(STDIN_FILENO, save_stdin);
	dup2(STDOUT_FILENO, save_stdout);
	close(save_stdin);
	close(save_stdout);
}

void	execute_command_lst(t_list *cmd)
{
	t_cmd_info	*info;
	int			i;
	
	info = scan_info(cmd);
	i = 0;
	while (i < info->lst_size)
	{
		exec_cmd(cmd, info, i);
		cmd = cmd->next;
		i++;
	}
	close_pipes(info);
	free_info(info);
}
