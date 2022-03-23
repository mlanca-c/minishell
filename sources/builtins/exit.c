/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:44:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/23 10:43:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_options(t_list *options);

int	exit_builtin(t_cmd *command)
{
	printf("exit\n");
	if (command->suffix && !handle_options(command->suffix))
		return (SUCCESS);
	exit_shell();
	return (SUCCESS);
}

static int	handle_options(t_list *options)
{
	t_ctrl	*controllers;

	controllers = scan_controllers(NULL);
	if (!ft_str_isnumeric(options->content))
	{
		printf("%s: exit: %s: numeric argument required\n", SHELL,
				options->content);
		controllers->return_value = 255;
	}
	else if (ft_lst_size(options) > 1)
	{
		printf("%s: too many options\n", SHELL);
		return (0);
	}
	else
		controllers->return_value = ft_atoi(options->content);
	return (1);
}
