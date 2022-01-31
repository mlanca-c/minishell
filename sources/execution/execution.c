/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:12:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 16:08:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function focuses on the execution part of the shell */
void	execution(void)
{
	t_ast	*parser_tree;

	parser_tree = init_controllers(NULL)->parser_tree;
	if (init_controllers(NULL)->debugger)
		print_commands(init_controllers(NULL)->parser_tree);
	execute_list(parser_tree);
}

/* This function executes a command depending on the parser_tree node */
void	execute_command(t_ast *parser_tree)
{
	if (!parser_tree)
		return ;
	if (scan_node(parser_tree)->type == Simple_Command)
		word_expansion(scan_node(parser_tree)->cmd);
	printf("Expanded: ");print_command(scan_node(parser_tree)->cmd);

}

/* This function executes a pipeline depending on the parser_tree node */
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

/* This function executes a list depending on the parser_tree node */
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

/* This function scans a t_node type from a parser_tree->content */
t_node	*scan_node(t_ast *parser_tree)
{
	if (!parser_tree)
		return (NULL);
	return ((t_node *)parser_tree->content);
}
