/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/21 16:17:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_lst(t_list *cmd)
{
	t_cmd_info	*info;
	int			i;

	info = scan_info(cmd);
	i = 0;
	while (cmd && info->return_value != -1)
	{
		info->return_value = implement_cmd(cmd, info, i);
		cmd = cmd->next;
		i++;
	}
	reset_ios(true, true);
	if (info->heredoc_file)
		unlink(info->heredoc_file);
	free_info(info);
}

int	implement_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	t_cmd		*command;

	command = (t_cmd *)cmd->content;
	t_pipe_init(command, index);
	if (set_ios(command) == FAILURE)
		return (FAILURE);
	if (do_redirs(command) == FAILURE)
		return (FAILURE);
	reset_ios(info->io->reset_in, info->io->reset_out);
	if (info->return_value == SUCCESS)
	{
		if (is_builtin(command))
			info->status = exec_builtin(command);
		else
			exec_program(command);
	}
	if (info->status != 0)
		return (info->status);
	return (SUCCESS);
}

int	exec_builtin(t_cmd *command)
{
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	if (ft_strcmp(command->name, "cd") == 0)
		controllers->return_value = cd_builtin(command);
	if (ft_strcmp(command->name, "env") == 0)
		controllers->return_value = env_builtin(command);
	if (ft_strcmp(command->name, "pwd") == 0)
		controllers->return_value = pwd_builtin(command);
	if (ft_strcmp(command->name, "echo") == 0)
		controllers->return_value = echo_builtin(command);
	if (ft_strcmp(command->name, "export") == 0)
		controllers->return_value = export_builtin(command);
	if (ft_strcmp(command->name, "unset") == 0)
		controllers->return_value = unset_builtin(command);
	if (ft_strcmp(command->name, "exit") == 0)
		controllers->return_value = exit_builtin(command);
	return (controllers->return_value);
}

void	sa(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	else if (signum == SIGQUIT)
		printf("Quit: %d\n", signum);
}

void	exec_program(t_cmd *command)
{
	pid_t		pid;
	t_cmd_info	*info;

	info = scan_info(NULL);
	signal(SIGINT, sa);
	signal(SIGQUIT, sa);
	pid = fork();
	if (pid < 0)
		exit_shell();
	else if (pid == 0)
		exec_child(command);
	waitpid(pid, &info->status, 0);
	exec_parent();
	signals();
}
