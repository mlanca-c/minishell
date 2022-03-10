/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:28:23 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free_info(info);
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

/*
void	exec_builtin(t_cmd *cmd)
{
	t_ctrl *controllers;
	
	controllers = scan_controllers(NULL);
	if (ft_strncmp(cmd->name, "cd", 2))
		controllers->return_value = cd_builtin(cmd);
	if (ft_strncmp(cmd->name, "env", 3))
		controllers->return_value = env_builtin();
	if (ft_strncmp(cmd->name, "pwd", 3))
		controllers->return_value = pwd_builtin();
	if (ft_strncmp(cmd->name, "echo", 4))
		controllers->return_value = echo_builtin(cmd);
	if (ft_strncmp(cmd->name, "export", 6))
		controllers->return_value = export_builtin(cmd);
	//if (ft_strncmp(cmd->name, "unset", 5))
	//	controllers->return_code = unset_builtin(cmd);
	//if (ft_strncmp(cmd->name, "exit", 4))
	//	controllers->return_code = exit_builtin(cmd);
}
*/

void	exec_program(t_cmd *command)
{
	pid_t		pid;
	t_cmd_info	*info;

	info = scan_info(NULL);
	pid = fork();
	if (pid < 0)
		exit_shell();
	else if (pid == 0)
	{
		//set_pipes(info->pipes, command, index);
		close(info->fd[0]);
		// if (info->has_outfile == false && index < info->lst_size - 1)
			// dup2(info->fd[1], STDOUT_FILENO);
		//close_pipes(info);
		exec_child(command);
	}
	close(info->fd[1]);
	//close_pipes(info);
	waitpid(pid, &info->status, 0);
	exec_parent();
}
