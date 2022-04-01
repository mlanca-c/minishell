/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:10 by josantos          #+#    #+#             */
/*   Updated: 2022/04/01 12:11:04 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd)
{
	char		*path;
	char		**envp_str;
	t_dict		*envp_dict;
	char		**argv;
	int			i;

	signals_child();
	envp_dict = scan_controllers(NULL)->envp;
	if (has_path(cmd))
		path = ft_strdup(cmd->name);
	else
		path = get_path(cmd);
	argv = get_array(cmd);
	envp_str = ft_dict_to_arr(envp_dict, "=");
	execve(path, argv, envp_str);
	ft_free_dpointer(envp_str);
	i = 0;
	while (argv[i])
		free(argv[i++]);
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
		controllers->return_value = WTERMSIG(info->status) + SGN;
}
