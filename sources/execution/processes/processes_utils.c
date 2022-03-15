/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:51:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/15 17:58:33 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_path(t_cmd *command)
{
	bool	checker;

	checker = false;
	if (command->name)
	{
		if (ft_strncmp(command->name, ".", 1) == 0)
			checker = true;
		else if (ft_strncmp(command->name, "/", 1) == 0)
			checker = true;
	}
	return (checker);
}

char	*get_path(t_cmd *command)
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
	correct_path = check_stat(paths, command);
	free(path);
	ft_free_dpointer(paths);
	return (correct_path);
}

char	*check_stat(char **paths, t_cmd *command)
{
	char		*correct_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	correct_path = NULL;
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], command->name);
		if (!correct_path)
			exit_shell();
		if (stat(correct_path, &statbuf) == EXIT_SUCCESS)
			break ;
		free(correct_path);
		correct_path = NULL;
		i++;
	}
	if (correct_path == NULL)
		correct_path = ft_strdup("");
	return (correct_path);
}

char	**get_array(t_cmd *command)
{
	char	**array;
	int		i;

	array = ft_calloc(ft_lst_size(command->suffix) + 2, sizeof(char *));
	if (!array)
		exit_shell();
	array[0] = ft_strdup(command->name);
	i = 1;
	while (command->suffix)
	{
		array[i++] = ft_strdup(command->suffix->content);
		command->suffix = command->suffix->next;
	}
	array[i] = NULL;
	return (array);
}

void	handle_error(t_cmd *command)
{
	if (errno == EACCES)
	{
		process_err(command->name, "Permission denied\n");
		exit(COMMAND_FAILURE);
	}
	if (errno == ENOENT)
	{
		process_err(command->name, "command not found\n");
		exit(COMMAND_NOT_FOUND);
	}
}
