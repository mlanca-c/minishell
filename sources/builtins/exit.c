/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:44:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/09 21:07:31 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_builtin(t_cmd *command)
{
	(void)command;
	ft_ast_clear(scan_controllers(NULL)->parser_tree, free_node);
	ft_lst_clear(scan_controllers(NULL)->token_list, free_token);
	exit_shell(SUCCESS);
	return (SUCCESS);
}
