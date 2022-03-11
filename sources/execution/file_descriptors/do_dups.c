/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:05:50 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 15:42:19 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_dup(int fd)
{
	int			new_fd;

	new_fd = dup(fd);
	if (new_fd == -1)
	{
		perror("dup Error\n");
		exit_shell();
	}
	return (new_fd);
}

int	do_dup2(int	old_fd, int new_fd)
{
	int			ret_fd;
	
	ret_fd = dup2(old_fd, new_fd);
	if (ret_fd == -1)
	{
		perror("dup2 Error\n");
		exit_shell();
	}
	return (ret_fd);
}