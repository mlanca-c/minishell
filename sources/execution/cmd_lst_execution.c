/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:14 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 03:51:17 by josantos         ###   ########.fr       */
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
		reset_ios(true, true);
		if (info->heredoc_file)
			unlink(info->heredoc_file);
		cmd = cmd->next;
		i++;
	}
	free_info(info);
}

int	implement_cmd(t_list *cmd, t_cmd_info *info, int index)
{
	t_cmd		*command;

	command = (t_cmd *)cmd->content;
	t_pipe_init(command, index);
	set_ios(command);
	do_redirs(command);
	reset_ios(info->io->reset_in, info->io->reset_out);

	
	/*info->og_fd->saved_stdin = do_dup(STDIN_FILENO);
	info->og_fd->saved_stdout = do_dup(STDOUT_FILENO);
	 info->return_value = check_infiles(command);
	if (info->return_value == SUCCESS)
		info->return_value = check_outfiles(command);
	if (info->return_value == SUCCESS && info->lst_size > 1)
		set_pipes(index);*/
	if (info->return_value == SUCCESS)
	{
		/*if (is_builtin(command))
			info->status = exec_builtin(command);
		else*/
		exec_program(command);
	}
	// if (index < info->lst_size - 1)
		// info->inside_pipe = true;
	// reset_og_fds(info);
	//	dup2(info->og_fd->saved_stdin, STDIN_FILENO);
	//dup2(info->og_fd->saved_stdout, STDOUT_FILENO);
	//close(info->og_fd->saved_stdin);
	//close(info->og_fd->saved_stdout);
	if (info->status != 0)
		return (info->status);
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
		//close(info->pipe_fd[READ]);
		exec_child(command);
	}
	//close(info->pipe_fd[WRITE]);
	waitpid(pid, &info->status, 0);
	exec_parent();
}
