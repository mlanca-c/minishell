/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:51:12 by josantos          #+#    #+#             */
/*   Updated: 2022/02/28 15:20:50 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_stat(char **path, t_cmd *cmd)
{
	char		*correct_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	correct_path = NULL;
	while (path[i])
	{
		correct_path = ft_strjoin(path[i], cmd->name);
		if (!correct_path)
			exit_shell();
		if (stat(correct_path, &statbuf) == EXIT_SUCCESS)
			break;
		free(correct_path);
		i++;
	}
	return (correct_path);
}

char	*get_path(t_cmd *cmd)
{
	t_ctrl	*controllers;
	char	**path;
	char	*temp;
	char	*correct_path;
	int		i;
	
	controllers = scan_controllers(NULL);
	while (controllers->envp)
		if (ft_strncmp(controllers->envp->key, "PATH=", 5) == 0)
			break ;
		else
			controllers->envp = controllers->envp->next;
	path = ft_split(controllers->envp->content, ':');
	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		i++;
	}
	correct_path = check_stat(path, cmd);
	free_dpointer(path);
	return (correct_path);
}

int	has_path(t_cmd *cmd)
{
	bool	checker;

	checker = true;
	if (ft_strncmp(cmd->name, "/", 1) || ft_strncmp(cmd->name, ".", 1))
		checker = false;
	return (checker);
}