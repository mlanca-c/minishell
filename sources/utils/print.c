/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:09:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 17:28:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	static char	*type[] = {"word", "assignment_word", "io_number", 	"pipe",
	"less", "great", "dless", "dgreat", "io_file", "and_if", "or_if",
	"left_parentesis", "right_parentesis", "eof", NULL};

	if (!token)
		printf("<text: null\ttype: EOF or ERROR>\n");
	else
		printf("<text: %s\ttype: %s>\n", token->text, type[token->type]);
}

void	print_controllers(void)
{
	int			i;
	t_ctrl		*controllers;
	static char	*err[] = {"null", NULL};

	controllers = init_controllers(NULL);
	printf("Controllers:\n");
	printf("\tShell: %s\n", controllers->shell);
	printf("\tPrompt: %s\n", controllers->prompt);
	i = 0;
	printf("\tpath:\n");
	while (controllers->path[i])
	{
		printf("\t\t- %s\n", controllers->path[i]);
		i++;
	}
	printf("\tHome: %s\n", controllers->home);
	printf("\ttoken_list: %p\n", &controllers->token_list);
	printf("\tparser_tree: %p\n", &controllers->parser_tree);
	printf("\terror: %s\n", err[controllers->error]);
}

void	print_parser_rec(t_ast *parser, int level)
{
	int			i;
	static char	*type[] = {"Simple Command", "Pipeline", "Assignment",
		"Here-Document", "And", "Or", NULL};

	if (!parser)
		return ;
	i = 0;
	while (i++ < level)
		printf(" | ");
	if (parser->content == Simple_Command)
	{
		printf("%s\n", type[(t_cmd_t)(parser->content)]);
		if (parser->left)
			return (print_command((t_cmd *)parser->left->content, level + 1));
		return ;
	}
	printf("%s\n", type[(t_cmd_t)(parser->content)]);
	print_parser_rec(parser->left, level + 1);
	print_parser_rec(parser->right, level + 1);
}

void	print_parser(t_ast *parser)
{
	print_parser_rec(parser, 0);
}

void	ident(int level)
{
	int	i;

	i = 0;
	while (i++ < level)
		printf(" | ");
}

void	print_command(t_cmd *command, int level)
{
	t_list	*arguments;

	arguments = (t_list *)command->prefix;
	if (arguments)
	{
		ident(level);
		printf("prefix: ");
	}
	while (arguments)
	{
		printf("%s ", (char *)arguments->content);
		arguments = arguments->next;
	}
	ident(level);
	printf("name: %s\n", command->name);
	arguments = (t_list *)command->suffix;
	if (arguments)
	{
		ident(level);
		printf("suffix: ");
	}
	while (arguments)
	{
		printf("%s ", (char *)arguments->content);
		arguments = arguments->next;
	}
}
