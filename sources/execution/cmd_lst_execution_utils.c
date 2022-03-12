/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:59 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 03:05:49 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	bool	checker;

	checker = true;
	if (ft_strncmp(cmd->name, "cd", 2) || ft_strncmp(cmd->name, "echo", 4)
		|| ft_strncmp(cmd->name, "env", 3) || ft_strncmp(cmd->name, "export", 6)
		|| ft_strncmp(cmd->name, "pwd", 3)
		|| ft_strncmp(cmd->name, "unset", 5)
		|| ft_strncmp(cmd->name, "exit", 4))
		checker = false;
	return (checker);
}

void	t_pipe_init(t_cmd *command, int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (index == 0 && info->lst_size > 1)
		command->pipe = Pipe_OUT;
	else if (index == 0)
		command->pipe = No_Pipe;
	else if (index > 0 && index < info->lst_size - 1)
		command->pipe = Pipe_In_Out;
	else if (index != 0 && index == info->lst_size - 1)
		command->pipe = Pipe_OUT;
}