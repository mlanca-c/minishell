/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:15:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/30 00:20:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	implement_cmd(t_cmd *command, int index);
static void	init_pipe(t_cmd *command, int index);

// This function executes the list of command
// Resets STDIN and STDOUT
// Deletes here_doc temp file
void	execute_command_lst(t_dlist *command)
{
	t_ctrl		*controllers;
	int			i;
	t_cmd_info	*info;

	controllers = scan_controllers(NULL);
	info = scan_info(command);
	i = ft_dlst_size(command);
	command = ft_dlist_last(command);
	while (command)
	{
		controllers->return_value = implement_cmd(command->content, i);
		command = command->previous;
		i--;
	}
	reset_ios(true, true);
	if (info->heredoc_file)
		unlink(info->heredoc_file);
	free_info(info);
}

// This function check pipe status of command.
// execute the pipes
// execute redirections
// execute the command itself
static int	implement_cmd(t_cmd *command, int index)
{
	t_ctrl		*controllers;
	t_cmd_info	*info;

	info = scan_info(NULL);
	controllers = scan_controllers(NULL);
	controllers->return_value = SUCCESS;
	init_pipe(command, index);
	// TODO: redirections
	// TODO: execution
	// if (controllers->return_value == SUCCESS)
	// {
	// 	if (is_builtin(command) && command->pipe == NO_PIPE)
	// 		info->status = exec_builtin(command);
	// 	else if (scan_envp("PATH", NULL) != 0 || has_path(command)
	// 		|| is_builtin(command))
	// 		exec_program(command);
	// 	else
	// 	{
	// 		path_err(command->name, "No such file or directory\n");
	// 		return (127);
	// 	}
	// }
	set_ios(command);
	return (controllers->return_value);
}

static void	init_pipe(t_cmd *command, int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (index == 1 && info->lst_size > 1)
		command->pipe = PIPE_OUT;
	else if (index == 1 && info->lst_size == 1)
		command->pipe = NO_PIPE;
	else if (index > 0 && index < info->lst_size)
		command->pipe = PIPE_IN_OUT;
	else if (index > 0 && index == info->lst_size)
		command->pipe = PIPE_IN;
	else
		printf("Congratulations! You managed to crash " SHELL "\n");
}
