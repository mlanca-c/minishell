/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:59 by josantos          #+#    #+#             */
/*   Updated: 2022/03/16 13:11:37 by mlanca-c         ###   ########.fr       */
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

void	t_pipe_init(t_cmd *command, int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (index == 0 && info->lst_size > 1)
		command->pipe = PIPE_OUT;
	else if (index == 0)
		command->pipe = NO_PIPE;
	else if (index > 0 && index < info->lst_size - 1)
		command->pipe = PIPE_IN_OUT;
	else if (index != 0 && index == info->lst_size - 1)
		command->pipe = PIPE_IN;
}
