/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resrap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:12:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 15:31:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute(t_dlist *command);
static void	resrap_list(t_ast *parser_tree);
static void	resrap_pipeline(t_ast *parser_tree);
static void	resrap_command(t_ast *parser_tree);

/* This function focuses on the execution part of the shell */
void	resrap(void)
{
	resrap_list(scan_controllers(NULL)->parser_tree);
	execute(scan_command(NULL));
}

/* This function executes a t_dlist of t_cmd types */
static void	execute(t_dlist *command)
{
	execute_command(command);
	ft_dlst_clear(command, free_command);
}

/* This function executes a command depending on the parser_tree node */
static void	resrap_command(t_ast *parser_tree)
{
	t_node	*node;

	if (!parser_tree)
		return ;
	node = scan_node(parser_tree);
	if (node->type == Simple_Command)
	{
		word_expansion(node->cmd);
		scan_command(node->cmd);
	}
}

/* This function executes a pipeline depending on the parser_tree node */
static void	resrap_pipeline(t_ast *parser_tree)
{
	if (!parser_tree)
		return ;
	if (scan_node(parser_tree)->type == Pipeline)
	{
		resrap_pipeline(parser_tree->left);
		resrap_pipeline(parser_tree->right);
	}
	else if (scan_node(parser_tree)->type == Or_List
		|| scan_node(parser_tree)->type == And_List)
		resrap_list(parser_tree);
	else
		resrap_command(parser_tree);
}

/* This function executes a list depending on the parser_tree node */
static void	resrap_list(t_ast *parser_tree)
{
	t_dlist	*command;

	if (!parser_tree)
		return ;
	command = NULL;
	if (scan_node(parser_tree)->type == And_List)
	{
		resrap_list(parser_tree->left);
		if (!scan_error(NULL))
			resrap_list(parser_tree->right);
	}
	else if (scan_node(parser_tree)->type == Or_List)
	{
		resrap_list(parser_tree->left);
		if (scan_error(NULL))
			resrap_list(parser_tree->right);
	}
	else
	{
		command = scan_command(NULL);
		if (command)
			execute(command);
		resrap_pipeline(parser_tree);
	}
}
