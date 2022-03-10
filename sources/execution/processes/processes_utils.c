/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:51:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:26:53 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_absolute_path(t_cmd *cmd)
{
	bool	checker;

	checker = true;
	if (ft_strncmp(cmd->name, "/", 1))
		checker = false;
	return (checker);
}

int	has_relative_path(t_cmd *cmd)
{
	bool	checker;

	checker = true;
	if (ft_strncmp(cmd->name, ".", 1))
		checker = false;
	return (checker);
}

char	*get_path(t_cmd *cmd)
{
	char	*path;
	char	**paths;
	char	*temp;
	char	*correct_path;
	int		i;
	
	path = ft_strdup(scan_envp("PATH=", NULL));
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(temp);
		i++;
	}
	correct_path = check_stat(paths, cmd);
	free(path);
	ft_free_dpointer(paths);
	return (correct_path);
}

char	*check_stat(char **paths, t_cmd *cmd)
{
	char		*correct_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	correct_path = NULL;
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], cmd->name);
		if (!correct_path)
			exit_shell();
		if (stat(correct_path, &statbuf) == EXIT_SUCCESS)
			break;
		free(correct_path);
		correct_path = NULL;
		i++;
	}
	if (correct_path == NULL)
		correct_path = ft_strdup("");
	return (correct_path);
}

char	**get_array(t_cmd *cmd)
{
	char	**array;
	int		i;

	array = ft_calloc(ft_lst_size(cmd->suffix) + 2, sizeof(char *));
	if (!array)
		exit_shell();
	array[0] = ft_strdup(cmd->name);
	i = 1;
	while (cmd->suffix)
	{
		array[i++] = ft_strdup(cmd->suffix->content);
		cmd->suffix = cmd->suffix->next;
	}
	array[i] = NULL;
	return (array);
}