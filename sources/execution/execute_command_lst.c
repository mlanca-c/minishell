/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:15:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 13:21:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	implement_cmd(t_cmd *command, int index);
static void	exec_program(t_cmd *command);
static void	exec_executable(t_cmd *command);
static char	*get_path(char *name);
static char	**command_to_array(t_cmd *command);

void	execute_command_lst(t_dlist *command)
{
	t_ctrl		*controllers;
	int			i;
	t_cmd_info	*info;

	controllers = scan_controllers(NULL);
	info = scan_info(command);
	i = ft_dlst_size(command);
	command = ft_dlst_last(command);
	while (command)
	{
		controllers->return_value = implement_cmd(command->content, i);
		command = command->previous;
		i--;
	}
	while (info->pid_lst)
	{
		waitpid(info->pid_lst->data, &info->status, 0);
		info->pid_lst = info->pid_lst->next;
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
	set_ios(command);								// Pipes are secured
	controllers->return_value = do_redirs(command);	// TODO: redirections
	// print_info();
	reset_ios(info->io->reset_in, info->io->reset_out);
	if (controllers->return_value == SUCCESS && is_builtin(command)
		&& command->pipe == NO_PIPE)
		controllers->return_value = exec_builtin(command);
	else if (controllers->return_value == SUCCESS)
		exec_program(command);
	return (controllers->return_value);
}

static void	exec_program(t_cmd *command)
{
	pid_t		pid;
	t_cmd_info	*info;

	info = scan_info(NULL);
	// Signal handling
	pid = safe_keeping(fork());
	if (pid == 0)	// Child Proccess
	{
		if (is_builtin(command))
		{
			exit(exec_builtin(command));
		}
		exec_executable(command);
	}
	ft_stack_add_front(&info->pid_lst, ft_stack_new(pid));
}

static void	exec_executable(t_cmd *command)
{
	// Signal Handling
	t_dict	*envp;
	char	**env;
	char	**command_array;
	char	*path;

	printf("Executing: %s\n", command->name);
	envp = scan_controllers(NULL)->envp;
	path = get_path(command->name);
	env = ft_dict_to_arr(envp, "=");
	command_array = command_to_array(command);
	execve(path, command_array, env);
	// Error handling.
}

static char	*get_path(char *name)
{
	char		**scan;
	char		*path;
	int			i;
	struct stat	statbuf;

	if (!name)
		return (NULL);
	if (name[0] == '/' || name[0] == '.')
		return (ft_strdup(name));
	scan = scan_path();
	i = 0;
	while (scan[i])
	{
		path = ft_strjoin(scan[i], name);
		if (stat(path, &statbuf) == SUCCESS)
			break ;
		free(path);
		path = NULL;
	}
	printf("Path: %s\n", path);
	return (path);
}

static char	**command_to_array(t_cmd *command)
{
	char	**array;
	int		i;

	array = ft_calloc(ft_dlst_size(command->suffix) + 2, sizeof(char *));
	if (!array)
		exit_shell();
	array[0] = ft_strdup(command->name);
	i = 1;
	while (command->suffix)
	{
		array[i++] = ft_strdup(command->suffix->content);
		command->suffix = command->suffix->next;
	}
	array[i] = NULL;
	return (array);
}
