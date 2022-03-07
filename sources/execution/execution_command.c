/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/07 21:46:30 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	int		save_stdin;
	int		save_stdout;
	t_cmd	*command;

	command = (t_cmd *)cmd->content;
	save_stdin = dup(STDIN_FILENO);
	save_stdout = dup(STDOUT_FILENO);
	info->return_value = check_infiles(command);
	check_outfiles(command);
	if (info->return_value == SUCCESS)
	{
		/*if (is_builtin(command))
			exec_builtin(command);
		else*/
			exec_program(command, index);
	}
	exec_parent(info);
	if (index < info->lst_size - 1)
		dup2(info->fd[0], STDIN_FILENO);
	else
		dup2(STDIN_FILENO, save_stdin);
	if (info->has_outfile == false)
		dup2(STDOUT_FILENO, save_stdout);
	// dup2(STDOUT_FILENO, save_stdout);
	// close(save_stdin);
	// close(save_stdout);
}

void	execute_command_lst(t_list *cmd)
{
	t_cmd_info	*info;
	int			i;
	
	info = scan_info(cmd);
	i = 0;
	while (cmd && info->status != -1)
	{
		exec_cmd(cmd, info, i);
		cmd = cmd->next;
		i++;
	}
	//close_pipes(info, 0);
	//free_info(info);
}
