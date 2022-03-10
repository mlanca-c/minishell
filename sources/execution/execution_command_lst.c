/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 02:53:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	set_pipes(int index)
{
	t_cmd_info	*info;
	
	info = scan_info(NULL);
	if (index < info->lst_size - 1)
	{
		if (pipe(info->fd) == -1)
			exit_shell();
		if (info->has_outfile == false)
			dup2(info->fd[1], STDOUT_FILENO);
		// if (info->has_infile == false && index != 0)
			// dup2(info->fd[0], STDIN_FILENO);
	}
}
*/

void	execute_command_lst(t_list *cmd)
{
	t_cmd_info	*info;
	t_ctrl		*controllers;
	
	info = scan_info(cmd);
	controllers = scan_controllers(NULL);
	while (cmd && info->status != -1)
	{
		controllers->return_value = exec_cmd(cmd);
		cmd = cmd->next;
		info->index += 1;
	}
	//close_pipes(info, 0);
	free(info);
}

int	exec_cmd(t_list *cmd)
{
	t_cmd	*command;

	command = (t_cmd *)cmd->content;
	save_origin_fds();
	if (handle_redirs(command) == SUCCESS)
		return (cmd_execution(command));
	else
		return (FAILURE);
}
	/*int		save_stdin;
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
		//if (is_builtin(command))
			//exec_builtin(command);
		//else
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
}*/

int	cmd_execution(t_cmd *command)
{
	/*if (ft_strncmp(command->name, "cd", 2))
		return (cd_builtin(command));
	else if (ft_strncmp(command->name, "env", 3))
		return (env_builtin());
	else if (ft_strncmp(command->name, "pwd", 3))
		return (pwd_builtin());
	else if (ft_strncmp(command->name, "echo", 4))
		return (echo_builtin(command));
	else if (ft_strncmp(command->name, "export", 6))
		return (export_builtin(command));
	//else if (ft_strncmp(command->name, "unset", 5))
	//return (unset_builtin(command));
	//else if (ft_strncmp(command->name, "exit", 4))
	//return (exit_builtin(command));
	else*/
		return (exec_program(command));
}

int	exec_program(t_cmd *command)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("PID Failure\n");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
		return (exec_child(command));
	else
		return (exec_parent(pid));
}