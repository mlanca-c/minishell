/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/03/23 12:08:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_home(t_cmd *command);
static int	handle_minus(t_cmd *command);
static int	handle_envp(char *old);

int	cd_builtin(t_cmd *command)
{
	char	*old;

	old = getcwd(NULL, 0);
	if (!command->suffix)
		return (handle_home(command));
	else if (ft_strcmp(command->suffix->content, "-") == 0)
		return (handle_minus(command));
	else if (opendir(command->suffix->content))
		chdir(command->suffix->content);
	else if (errno)
	{
		if (errno == ENOENT)
			cd_err(command, "No such file or directory");
		else
			cd_err(command, "Not a directory");
		return (FAILURE);
	}
	handle_envp(old);
	return (SUCCESS);
}

static int	handle_home(t_cmd *command)
{
	char	*old;

	old = getcwd(NULL, 0);
	if (!ft_dict_key_exists(scan_controllers(NULL)->envp, "HOME"))
	{
		builtin_err(command, "HOME not set");
		return (FAILURE);
	}
	else if (!scan_envp("HOME", NULL)[0])
		return (FAILURE);
	if (opendir(scan_envp("HOME", NULL)))
		chdir(scan_envp("HOME", NULL));
	else if (errno)
	{
		if (errno == ENOENT)
			cd_err(command, "No such file or directory");
		else
			cd_err(command, "Not a directory");
		return (FAILURE);
	}
	handle_envp(old);
	return (SUCCESS);
}

static int	handle_minus(t_cmd *command)
{
	t_dict	*envp;
	char	*old;

	envp = scan_controllers(NULL)->envp;
	old = getcwd(NULL, 0);
	if (opendir(scan_envp("OLDPWD", NULL)))
	{
		chdir(scan_envp("OLDPWD", NULL));
		printf("%s\n", scan_envp("OLDPWD", NULL));
	}
	else
	{
		builtin_err(command, "OLDPWD not set");
		if (!ft_dict_key_exists(envp, "OLDPWD"))
			ft_dict_add_back(&envp, ft_dict_new(ft_strdup("OLDPWD"), NULL));
		return (FAILURE);
	}
	handle_envp(old);
	return (SUCCESS);
}

static int	handle_envp(char *old)
{
	t_dict	*envp;

	envp = scan_controllers(NULL)->envp;
	if (!ft_dict_key_exists(envp, "OLDPWD"))
		ft_dict_add_back(&envp, ft_dict_new(ft_strdup("OLDPWD"), NULL));
	scan_envp("OLDPWD", old);
	if (!ft_dict_key_exists(envp, "PWD"))
		ft_dict_add_back(&envp, ft_dict_new(ft_strdup("PWD"), NULL));
	scan_envp("PWD", getcwd(NULL, 0));
	return (SUCCESS);
}
