/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/01/28 15:49:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dir(char *cd_arg)
{
	DIR	*checker;
	t_ctrl *controllers;
	
	controllers = init_controllers(NULL);
	if (ft_strncmp(cd_arg, "-", 1))
		checker = opendir(controllers->prev_dir);
	else
		checker = opendir(cd_arg);
	if (!checker)
			return (BUILTIN_FAILURE);
	else
		return (0);
}

int	cd_builtin(t_cmd *cmd)
{
	static int	i = 0;
	t_ctrl	*controllers;

	controllers = init_controllers(NULL);
	if (!cmd->suffix)
		chdir(controllers->home);
	else if (check_dir(cmd->suffix->content))
		return (BUILTIN_FAILURE);
	else
	{
		if (ft_strlen(cmd->suffix->content) == 1
			&& !ft_strncmp(cmd->suffix->content, "-", 1))
			chdir(controllers->prev_dir);
		else
			chdir(cmd->suffix->content);
		controllers->prev_dir = controllers->dir_path;
		controllers->dir_path = getcwd(NULL, 0);
		i++;
	}
	return (SUCCESS);
}
