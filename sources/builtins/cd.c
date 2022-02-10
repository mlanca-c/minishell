/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:01:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dir(char *cd_arg)
{
	DIR		*checker;

	if (!ft_strncmp(cd_arg, "-", 1))
		checker = opendir(scan_old_pwd(NULL));
	else
		checker = opendir(cd_arg);
	if (!checker)
	{
		printf("shit\n");
		return (BUILTIN_FAILURE);
	}
	else
		return (0);
}

int	cd_builtin(t_cmd *cmd)
{
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	if (!cmd->suffix)
		chdir(controllers->home);
	else
	{
		if (check_dir(cmd->suffix->content))
			return (BUILTIN_FAILURE);
		if (ft_strlen(cmd->suffix->content) == 1
			&& !ft_strncmp(cmd->suffix->content, "-", 1))
			chdir(scan_old_pwd(NULL)[7]);
		else
			chdir(cmd->suffix->content);
	}
	scan_old_pwd(scan_pwd(NULL));
	scan_pwd(getcwd(NULL, 0));
	printf("%s\n", scan_pwd(NULL));
	return (SUCCESS);
}
