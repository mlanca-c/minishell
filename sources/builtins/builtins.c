/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:49:31 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 11:50:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *command)
{
	if (!command->name)
		return (false);
	if (ft_strcmp(command->name, "cd") == 0
		|| ft_strcmp(command->name, "echo") == 0
		|| ft_strcmp(command->name, "env") == 0
		|| ft_strcmp(command->name, "export") == 0
		|| ft_strcmp(command->name, "pwd") == 0
		|| ft_strcmp(command->name, "unset") == 0
		|| ft_strcmp(command->name, "exit") == 0)
		return (true);
	return (false);
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
