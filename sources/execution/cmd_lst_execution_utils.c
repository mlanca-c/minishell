/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:59 by josantos          #+#    #+#             */
/*   Updated: 2022/03/15 17:52:55 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *command)
{
	if (!command->name)
		return (false);
	if (ft_strncmp(command->name, "cd", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "echo", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "env", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "export", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "pwd", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "unset", ft_strlen(command->name)) == 0
		|| ft_strncmp(command->name, "exit", ft_strlen(command->name)) == 0)
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
