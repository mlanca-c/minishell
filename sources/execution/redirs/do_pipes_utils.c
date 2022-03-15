/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:57:54 by josantos          #+#    #+#             */
/*   Updated: 2022/03/14 16:20:09 by mlanca-c         ###   ########.fr       */
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

	if (fd == -1)
		return (FAILURE);
	ret = close(fd);
	if (ret == -1)
	{
		perror("close Error\n");
		exit_shell();
	}
	return (ret);
}
