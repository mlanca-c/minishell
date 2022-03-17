/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:44:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/17 12:10:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_builtin(t_cmd *command)
{
	(void)command;
	ft_ast_clear(scan_controllers(NULL)->parser_tree, free_node);
	ft_lst_clear(scan_controllers(NULL)->token_list, free_token);
	printf("exit\n");
	if (command->suffix)
		printf("%s: exit: %s: numeric argument required\n", SHELL, (char *)command->suffix->content);
	free_command((void *)command);
	exit_shell();
	return (SUCCESS);
}
