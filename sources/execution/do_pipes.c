/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:11:20 by josantos          #+#    #+#             */
/*   Updated: 2022/02/23 10:22:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**init_pipes(t_cmd_info *info)
{
	int	**pipes;
	int	i;

	if (info->lst_size < 2)
		return (0);
	pipes = ft_calloc(info->lst_size, sizeof(int *));
	if (!pipes)
		exit_shell();
	i = 0;
	while (i < info->lst_size - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
		{
			free_dintpointer(pipes);
			exit_shell();
		}
		if (pipe(pipes[i]) == -1)
		{
			free_dintpointer(pipes);
			exit_shell();
		}
		i++;
	}
	return (pipes);
}

int	open_files(t_cmd *command, int index, t_cmd_info *info)
{
	
}