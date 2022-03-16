/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:59 by josantos          #+#    #+#             */
/*   Updated: 2022/03/14 12:36:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	bool	checker;

	checker = false;
	if (ft_strncmp(cmd->name, "cd", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "echo", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "env", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "export", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "pwd", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "unset", ft_strlen(cmd->name)) == 0
		|| ft_strncmp(cmd->name, "exit", ft_strlen(cmd->name)) == 0)
		checker = true;
	return (checker);
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
