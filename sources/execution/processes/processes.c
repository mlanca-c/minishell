/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/02/28 19:07:27 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd)
{
	char		*path;
	char		**envp;
	char		**command;
	t_ctrl		*controllers;
	t_cmd_info	*info;
	
	info = scan_info(NULL);
	controllers = scan_controllers(NULL);
	close_pipes(info);
	if (has_path(cmd))
		path = ft_strdup(cmd->name);
	else
		path = get_path(cmd);
	command = get_array(cmd);
	envp = lst_tostr(controllers->env);
	execve(path, command, envp);
	free(command);
	if (path)
		free(path);
	free_dpointer(envp);
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