/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 15:31:40 by josantos         ###   ########.fr       */
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
	free_info(info);
}

int	exec_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	t_cmd	*command;

	command = (t_cmd *)cmd->content;
	info->og_fd->saved_stdin = do_dup(STDIN_FILENO);
	info->og_fd->saved_stdout = do_dup(STDOUT_FILENO);
	info->return_value = check_heredoc(command);
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
		dup2(info->pipe_fd[READ], STDIN_FILENO);
	else
		dup2(info->og_fd->saved_stdin, STDIN_FILENO);
	dup2(info->og_fd->saved_stdout, STDOUT_FILENO);
	close(info->og_fd->saved_stdin);
	close(info->og_fd->saved_stdout);
	return (SUCCESS);
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
		close(info->pipe_fd[READ]);
		exec_child(command);
	}
	close(info->pipe_fd[WRITE]);
	waitpid(pid, &info->status, 0);
	exec_parent();
}
