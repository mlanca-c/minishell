/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:59 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:12:36 by josantos         ###   ########.fr       */
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