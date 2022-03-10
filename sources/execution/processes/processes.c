/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:24:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd)
{
	char		*path;
	char		**envp_str;
	t_dict		*envp_dict;
	char		**argv;
	
	signal(SIGINT, SIG_DFL);
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

void	exec_parent(void)
{
	int			status;
	t_ctrl		*controllers;
	t_cmd_info	*info;
	
	controllers = scan_controllers(NULL);
	info = scan_info(NULL);
	if (WIFEXITED(info->status))
		controllers->return_value = WEXITSTATUS(status);
	else if (WIFSIGNALED(info->status))
		controllers->return_value = WTERMSIG(status);
}
