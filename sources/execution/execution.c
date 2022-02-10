/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:12:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 21:44:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function focuses on the execution part of the shell */
void	resrap(void)
{
	execute_list(scan_controllers(NULL)->parser_tree);
	execute(scan_command(NULL));
}

/* This function executes a t_list of t_cmd types */
void	execute(t_list *command)
{
	t_cmd	*node;

	printf("{ Execute }:\n");
	while (command)
	{
		node = (t_cmd *)command->content;
		print_command(node);
		command = command->next;
	}
	ft_lst_clear(command, free_command);
}

/* This function executes a command depending on the parser_tree node */
void	execute_command(t_ast *parser_tree)
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
	t_list	*command;

	if (!parser_tree)
		return ;
	command = NULL;
	if (scan_node(parser_tree)->type == And_List)
	{
		execute_list(parser_tree->left);
		if (!scan_error(NULL))
			execute_list(parser_tree->right);
	}
	else if (scan_node(parser_tree)->type == Or_List)
	{
		execute_list(parser_tree->left);
		if (scan_error(NULL))
			execute_list(parser_tree->right);
	}
	else
	{
		command = scan_command(NULL);
		if (command)
			execute(command);
		execute_pipeline(parser_tree);
	}
}
