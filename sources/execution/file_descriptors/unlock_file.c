/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:54:44 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 01:10:01 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unlock_file(char *filename, int flags, mode_t mode)
{
	int		new_fd;
	t_ctrl	*controllers;
	
	controllers = scan_controllers(NULL);
	if (mode)
		new_fd = open(file, flags, mode);
	else
		new_fd = open (file, flags);
	if (new_fd == -1)
	{
		ft_putstr_fd(controllers->prompt, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(filename);
	}
	return (new_fd);
}