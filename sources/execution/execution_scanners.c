/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_scanners.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:23:06 by josantos          #+#    #+#             */
/*   Updated: 2022/02/11 17:06:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	do_builtins(t_cmd *cmd)
{
	//if (!ft_strncmp(cmd->name, "cd", 2) && ft_strlen(cmd->name) == 2)
	//	cd_builtin(cmd);
	if (!ft_strncmp(cmd->name, "echo", 4) && ft_strlen(cmd->name) == 4)
		echo_builtin(cmd);
	//else if (!ft_strncmp(cmd->name, "env", 3) && ft_strlen(cmd->name) == 3)
	//	env_builtin();
	// else if (!ft_strncmp(cmd->name, "pwd", 3) && ft_strlen(cmd->name) == 3)
	//else if (!ft_strncmp(cmd->name, "pwd", ft_strlen(cmd->name)))
	//	pwd_builtin();
	//else if (!ft_strncmp(cmd->name, "export", 6) && ft_strlen(cmd->name) == 6)
	//	export_builtin(cmd);
	*/
	
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
