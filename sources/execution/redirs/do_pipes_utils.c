/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:57:54 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 18:59:49 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pipe(int fd[2])
{
	int			ret_fd;

	ret_fd = pipe(fd);
	if (ret_fd == -1)
	{
		perror("pipe Error\n");
		exit_shell();
	}
	return (ret_fd);
}

int	do_close(int fd)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
	{
		perror("close Error\n");
		exit_shell();
	}
	return (ret);
}