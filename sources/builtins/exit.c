/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:44:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/23 11:35:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_options(t_cmd *command);

int	exit_builtin(t_cmd *command)
{
	if (command->suffix && !handle_options(command))
		return (SUCCESS);
	printf("exit\n");
	exit_shell();
	return (SUCCESS);
}

static int	handle_options(t_cmd *command)
{
	t_ctrl	*controllers;
	t_list	*options;

	controllers = scan_controllers(NULL);
	options = command->suffix;
	if (!ft_str_isnumeric(options->content))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		builtin_err(command, "numeric argument required");
		controllers->return_value = 255;
		exit_shell();
	}
	else if (ft_lst_size(options) > 1)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		builtin_err(command, "too many options");
		return (0);
	}
	else
		controllers->return_value = ft_atoi(options->content);
	return (1);
}
