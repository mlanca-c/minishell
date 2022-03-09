/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 11:21:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipes(int index)
{
	t_cmd_info	*info;
	
	info = scan_info(NULL);
	if (pipe(info->fd) == -1)
		exit_shell();
	if (info->has_outfile == false && index < info->lst_size - 1)
		dup2(info->fd[1], STDOUT_FILENO);
	// if (info->has_infile == false && index != 0)
		// dup2(info->fd[0], STDIN_FILENO);
}

void	exec_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	int		save_stdin;
	int		save_stdout;
	t_cmd	*command;

	command = (t_cmd *)cmd->content;
	save_stdin = dup(STDIN_FILENO);
	save_stdout = dup(STDOUT_FILENO);
	info->return_value = check_infiles(command);
	if (info->return_value == SUCCESS)
		check_outfiles(command);
	set_pipes(index);
	if (info->return_value == SUCCESS)
	{
		/*if (is_builtin(command))
			exec_builtin(command);
		else*/
			exec_program(command);
	}
	if (index < info->lst_size - 1)
		dup2(info->fd[0], STDIN_FILENO);
	else
		dup2(save_stdin, STDIN_FILENO);
	//if (info->has_outfile == false)
	dup2(save_stdout, STDOUT_FILENO);
	close(save_stdin);
	close(save_stdout);
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
