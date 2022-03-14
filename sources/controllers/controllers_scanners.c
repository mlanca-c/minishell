/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers_scanners.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:42:35 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/02 12:06:31 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function returns the main variable controllers */
t_ctrl	*scan_controllers(char *envp[])
{
	static t_ctrl	*controllers = NULL;

	if (!envp)
		return (controllers);
	controllers = (t_ctrl *)ft_calloc(1, sizeof(t_ctrl));
	if (!controllers)
		exit_shell();
	controllers->shell = SHELL;
	controllers->prompt = PROMPT;
	controllers->envp = controllers_get_envp(envp);
	controllers->error = null;
	controllers->return_value = 0;
	controllers->debugger = false;
	return (controllers);
}

/* This function returns an error - t_err_t */
t_err_t	scan_error(void *err)
{
	t_err_t	error;

	error = scan_controllers(NULL)->error;
	if (err)
		error = (t_err_t)err;
	return (error);
}

/* This function returns a value from envp - t_dict */
char	*scan_envp(char *key, char *value)
{
	t_dict	*envp;

	envp = scan_controllers(NULL)->envp;
	if (value)
		return (ft_dict_replace(envp, key, value));
	return (ft_dict_find(envp, key));
}

/* This function returns the last folder from controllers->directory */
char	**scan_path(void)
{
	char	*path;
	char	**split;
	int		i;

	path = ft_dict_find(scan_controllers(NULL)->envp, "PATH=");
	if (!path)
		return (NULL);
	split = ft_split(path, ':');
	i = 0;
	while (split[i])
	{
		path = split[i];
		split[i] = ft_strjoin(split[i], "/");
		free(path);
		i++;
	}
	return (split);
}

/* This function returns the directory name from controllers->envp */
char	*scan_directory(void)
{
	int		i;
	char	*directory;

	directory = scan_envp("PWD=", NULL);
	i = ft_strlen(directory) - 1;
	while (directory[i] && ft_strfind(&directory[i], "/") == -1)
		i--;
	return (&directory[++i]);
}
