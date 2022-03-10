/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 02:55:53 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_parent(pid_t pid)
{
	int			exit_status;
	t_cmd_info	*info;
	
	
	info = scan_info(NULL);
	if (waitpid(pid, &exit_status, 0) == -1)
	{
		perror("Process Failure\n");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	else if (WIFSIGNALED(exit_status))
		return (128 + WTERMSIG(exit_status));
	else
		return (EXIT_FAILURE);
}

int	exec_child(t_cmd *cmd)
{
	char		*path;
	char		**envp_str;
	t_dict		*envp_dict;
	char		**argv;
	// t_cmd_info	*info;
	
	signal(SIGINT, SIG_DFL);
	// info = scan_info(NULL);
	envp_dict = scan_controllers(NULL)->envp;
	if (has_relative_path(cmd) || has_absolute_path(cmd))
		path = ft_strdup(cmd->name);
	else
		path = get_path(cmd);
	argv = get_array(cmd);
	envp_str = ft_dict_to_arr(envp_dict, NULL);
	execve(path, argv, envp_str);
	ft_free_dpointer(envp_str);
	free(argv);
	free(path);
	if (errno == EACCES)
	{
		process_err(cmd->name, "Permission denied\n");
		exit(COMMAND_FAILURE);
	}
	if (errno == ENOENT)
	{
		process_err(cmd->name, "command not found\n");
		exit(COMMAND_NOT_FOUND);
	}
	exit(errno);
}

char	**lst_tostr(t_list *envp)
{
	char	**env;
	int		i;
	
	env = ft_calloc(ft_lst_size(envp), sizeof(char *));
	if (!env)
		exit_shell(MALLOC);
	i = 0;
	while (envp)
	{
		env[i++] = ft_strdup(envp->content);
		envp = envp->next;
	}
	return (env);
}

char	**get_array(t_cmd *cmd)
{
	char	**array;
	int		i;

	array = ft_calloc(ft_lst_size(cmd->suffix) + 2, sizeof(char *));
	if (!array)
		exit_shell(MALLOC);
	array[0] = ft_strdup(cmd->name);
	i = 1;
	while (cmd->suffix)
	{
		array[i++] = ft_strdup(cmd->suffix->content);
		cmd->suffix = cmd->suffix->next;
	}
	array[i] = NULL;
	return (array);
}