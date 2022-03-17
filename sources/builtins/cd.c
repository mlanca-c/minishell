/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/03/17 17:58:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(t_cmd *command)
{
	static bool	first = true;
	
	if (!command->suffix)
		chdir(scan_envp("HOME", NULL));
	else if (ft_strncmp(command->suffix->content, "-",
			ft_strlen(command->suffix->content)) == 0)
	{
		if (cd_builtin_minus(first) == FAILURE)
			return (FAILURE);
	}
	else if (opendir(command->suffix->content))
		chdir(command->suffix->content);
	else
	{
		builtin_err(command, "No such file or directory");
		return (FAILURE);
	}
	first = false;
	scan_envp("OLDPWD", ft_strdup(scan_envp("PWD", NULL)));
	scan_envp("PWD", getcwd(NULL, 0));
	return (SUCCESS);
}

int	cd_builtin_minus(bool first)
{
	if (first == true)
		{
			printf("crash-1.0$ cd: OLDPWD not set\n");
			return (FAILURE);
		}
		if (opendir(scan_envp("OLDPWD", NULL)))
		{
			chdir(scan_envp("OLDPWD", NULL));
			printf("%s\n", scan_envp("OLDPWD", NULL));
		}
		else
			return (FAILURE);
		return (SUCCESS);
}
