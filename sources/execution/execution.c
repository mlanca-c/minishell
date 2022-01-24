/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:12:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/24 14:42:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(void)
{
	t_ast	*parser_tree;

	parser_tree = init_controllers(NULL)->parser_tree;
	execute_list(parser_tree);
}

void	execute_list(t_ast *parser_tree)
{
	if (!parser_tree)
		return ;
	if (scan_node(parser_tree)->type == And_List)
	{
		execute_list(parser_tree->left);
		if (!find_error())
			execute_list(parser_tree->right);
	}
	else if (scan_node(parser_tree)->type == Or_List)
	{
		execute_list(parser_tree->left);
		if (find_error())
			execute_list(parser_tree->right);
	}
	else
		execute_pipeline(parser_tree);
}

void	execute_pipeline(t_ast *parser_tree)
{
	if (!parser_tree)
		return ;
	if (scan_node(parser_tree)->type == Pipeline)
	{
		execute_pipeline(parser_tree->left);
		execute_pipeline(parser_tree->right);
	}
	else if (scan_node(parser_tree)->type == Or_List
		|| scan_node(parser_tree)->type == And_List)
		execute_list(parser_tree);
	else
		execute_command(parser_tree);
}

void	execute_command(t_ast *parser_tree)
{
	if (!parser_tree)
		return ;
	if (scan_node(parser_tree)->type == Simple_Command)
	{
		word_expansion(scan_node(parser_tree)->cmd);
		// redirections(scan_node(parser_tree)->cmd);
		if (init_controllers(NULL)->debugger)
			print_commands(init_controllers(NULL)->parser_tree);
	}
}

t_node	*scan_node(t_ast *parser_tree)
{
	if (!parser_tree)
		return (NULL);
	return ((t_node *)parser_tree->content);
}
