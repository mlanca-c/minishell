/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:03:19 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 17:08:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	exit_shell_message(t_err_t error)
{
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	ft_putstr_fd(controllers->prompt, STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	exit_shell(error);
}

void	process_err(char *argv, char *message)
{
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}