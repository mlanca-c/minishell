/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_sanners.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:23:06 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 21:44:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function scans a t_node type from a parser_tree */
t_node	*scan_node(t_ast *parser_tree)
{
	if (!parser_tree)
		return (NULL);
	return ((t_node *)parser_tree->content);
}

/* This function scans a t_cmd type from a t_node */
t_list	*scan_command(t_cmd *command)
{
	static t_list	*command_list = NULL;
	t_list			*temporary;

	if (!command)
	{
		temporary = command_list;
		command_list = NULL;
		return (temporary);
	}
	ft_lst_add_back(&command_list, ft_lst_new(command));
	return (NULL);
}
