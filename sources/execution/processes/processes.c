/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 02:17:40 by josantos         ###   ########.fr       */
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
	if (has_path(cmd))
		path = ft_strdup(cmd->name);
	else
		path = get_path(cmd);
	argv = get_array(cmd);
	envp_str = ft_dict_to_arr(envp_dict, NULL);
	execve(path, argv, envp_str);
	ft_free_dpointer(envp_str);
	free(argv);
	free(path);
	handle_error(cmd);
	exit(EXIT_FAILURE);
}

void	exec_parent(void)
{
	t_ctrl		*controllers;
	t_cmd_info	*info;

	controllers = scan_controllers(NULL);
	info = scan_info(NULL);
	if (WIFEXITED(info->status))
		controllers->return_value = WEXITSTATUS(info->status);
	else if (WIFSIGNALED(info->status))
		controllers->return_value = WTERMSIG(info->status);
}
