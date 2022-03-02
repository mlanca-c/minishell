/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/03/02 12:18:50 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_parent(void)
{
	int			status;
	t_ctrl		*controllers;
	t_cmd_info	*info;
	
	controllers = scan_controllers(NULL);
	info = scan_info(NULL);
	while (info->pids)
	{
		waitpid(info->pids->data, &status, 0);
		if (WIFEXITED(status))
			controllers->return_value = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			controllers->return_value = WTERMSIG(status);
		ft_stack_remove(&info->pids);
	}
	ft_stack_clear(&info->pids);
}

void	exec_child(t_cmd *cmd)
{
	char		*path;
	char		**envp_str;
	t_dict		*envp_dict;
	char		**command;
	t_cmd_info	*info;
	
	int i = 0;
	
	printf("a\n");
	info = scan_info(NULL);
	envp_dict = scan_controllers(NULL)->envp;
	close_pipes(info);
	if (has_path(cmd))
		path = ft_strdup(cmd->name);
	else
		path = get_path(cmd);
	command = get_array(cmd);
	envp_str = dict_toarray(envp_dict);
	execve(path, command, envp_str);
	free(command);
	if (path)
		free(path);
	free_dpointer(envp_str);
	if (errno == EACCES)
	{
		strerror(errno);
		exit(COMMAND_FAILURE);
	}
	if (errno == ENOENT)
	{
		strerror(errno);
		exit(COMMAND_NOT_FOUND);
	}
}

char	**lst_tostr(t_list *envp)
{
	char	**env;
	int		i;
	
	env = ft_calloc(ft_lst_size(envp), sizeof(char *));
	if (!env)
		exit_shell();
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

	array = ft_calloc(ft_lst_size(cmd->suffix) + 1, sizeof(char *));
	if (!array)
		exit_shell();
	array[0] = ft_strdup(cmd->name);
	i = 1;
	while (cmd->suffix)
	{
		array[i++] = ft_strdup(cmd->suffix->content);
		cmd->suffix = cmd->suffix->next;
	}
	return (array);
}