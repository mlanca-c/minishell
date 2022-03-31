/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:03:19 by josantos          #+#    #+#             */
/*   Updated: 2022/03/31 11:23:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_err(char *argv, char *message)
{
	ft_putstr_fd(SHELL ": ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

void	cd_err(t_cmd *command, char *message)
{
	ft_putstr_fd(SHELL ": ", STDERR_FILENO);
	ft_putstr_fd(command->name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (command->suffix)
	{
		ft_putstr_fd(command->suffix->content, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	builtin_err(t_cmd *command, char *message)
{
	ft_putstr_fd(SHELL ": ", STDERR_FILENO);
	ft_putstr_fd(command->name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	open_err(char *file, char *message)
{
	ft_putstr_fd(SHELL ": ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

void	path_err(char *argv, char *message)
{
	ft_putstr_fd(SHELL ": ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}
