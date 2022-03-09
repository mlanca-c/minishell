/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:37:36 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 21:03:59 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	bool	checker;

	checker = true;
	if (ft_strncmp(cmd->name, "cd", 2) || ft_strncmp(cmd->name, "echo", 4)
		|| ft_strncmp(cmd->name, "env", 3) || ft_strncmp(cmd->name, "export", 6)
			|| ft_strncmp(cmd->name, "pwd", 3)
				|| ft_strncmp(cmd->name, "unset", 5)
					|| ft_strncmp(cmd->name, "exit", 4))
		checker = false;
	return (checker);
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
/*void	exec_program(t_cmd *command)
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
	exec_parent(info);
}
*/