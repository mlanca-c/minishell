/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:19:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/23 14:38:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_parser_node(t_cmd_t node, int level);
static void	print_parser_rec(t_ast *parser, int level);
static void	print_command(t_cmd *command);
static void	ident(int level);

/* This function prints the parser tree */
void	print_parser(void)
{
	t_ast	*parser;

	parser = scan_controllers(NULL)->parser_tree;
	printf("\n\n%s{ Parser }\n", RED);
	print_parser_rec(parser, 0);
	printf("%s", RESET);
}

static void	print_parser_rec(t_ast *parser, int level)
{
	t_node	*node;

	if (!parser)
		return ;
	node = (t_node *)parser->content;
	if (node->type == Simple_Command)
	{
		print_parser_node(node->type, level);
		if (node->cmd)
			return (print_command(node->cmd));
		return ;
	}
	print_parser_node((t_cmd_t)node->type, level);
	printf("\n");
	print_parser_rec(parser->left, level + 1);
	print_parser_rec(parser->right, level + 1);
}

static void	print_parser_node(t_cmd_t node, int level)
{
	static char	*type[] = {"[ Simple Command ]: ", "Pipeline", "And", "Or",
		NULL};

	ident(level);
	printf("%s", type[node]);
}

static void	print_command(t_cmd *command)
{
	print_command_lst(command->prefix);
	if (command->name)
		printf("%s ", command->name);
	print_command_lst(command->suffix);
	print_command_red(command->redirection);
	printf("\n");
}

static void	ident(int level)
{
	int	i;

	i = 0;
	while (i++ < level)
		printf(" . ");
}
