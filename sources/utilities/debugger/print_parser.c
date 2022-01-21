/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:19:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 00:45:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_parser_rec(t_ast *parser, int level);

/* This function prints the parser tree */
void	print_parser(void)
{
	t_ast	*parser;

	parser = init_controllers(NULL)->parser_tree;
	printf("\n\n%s{ Parser }\n", RED);
	print_parser_rec(parser, 0);
	printf("%s", RESET);
}

void	ident(int level)
{
	int	i;

	i = 0;
	while (i++ < level)
		printf(" . ");
}

void	print_parser_node(t_cmd_t node, int level)
{
	static char	*type[] = {"[ Simple Command ]: ", "Pipeline", "Assignment",
		"Here-Document", "And", "Or", NULL};

	ident(level);
	printf("%s", type[node]);
}

void	print_parser_rec(t_ast *parser, int level)
{
	if (!parser)
		return ;
	if (parser->content == Simple_Command)
	{
		print_parser_node((t_cmd_t)parser->content, level);
		if (parser->left)
			return (print_command((t_cmd *)parser->left->content));
		return ;
	}
	print_parser_node((t_cmd_t)parser->content, level);
	printf("\n");
	print_parser_rec(parser->left, level + 1);
	print_parser_rec(parser->right, level + 1);
}
