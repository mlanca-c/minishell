/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:00:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 17:36:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	handle_error(t_cmd *command)
// {
// 	if (errno == EACCES)
// 	{
// 		process_err(command->name, "Permission denied\n");
// 		exit(COMMAND_FAILURE);
// 	}
// 	else if (errno == ENOENT)
// 	{
// 		process_err(command->name, "command not found\n");
// 		exit(COMMAND_NOT_FOUND);
// 	}
// }

// void	check_error(void)
// {
// 	t_ctrl		*controllers;
// 	t_cmd_info	*info;

// 	controllers = scan_controllers(NULL);
// 	info = scan_info(NULL);
// 	if (WIFEXITED(info->status))
// 		controllers->return_value = WEXITSTATUS(info->status);
// 	else if (WIFSIGNALED(info->status))
// 		controllers->return_value = WTERMSIG(info->status) + SGN;
// }


