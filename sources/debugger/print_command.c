/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:37:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/25 10:19:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_commands_rec(t_ast *parser);
static void	print_command_template(t_cmd *command);

void	print_commands(t_ast *parser)
{
	printf("\n\n%s{ Commands }\n", YELLOW);
	print_commands_rec(parser);
	printf("%s", RESET);
}

void	print_command_red(t_list *red)
{
	static char	*type[] = {"<", ">", "<<", ">>", NULL};
	t_red		*content;

	if (!red)
		return ;
	while (red)
	{
		content = (t_red *)red->content;
		printf("%s %s ", type[content->io_type - 2], content->io_file);
		red = red->next;
	}
}

void	print_command_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}

static void	print_command_template(t_cmd *command)
{
	if (!command)
		return ;
	printf("{\n");
	printf(" [ prefix ]: ");
	if (command->prefix)
		print_command_lst(command->prefix);
	else
		printf("(null)");
	printf("\n");
	printf(" [ Name ]: %s\n", command->name);
	printf(" [ Suffix ]: ");
	if (command->suffix)
		print_command_lst(command->suffix);
	else
		printf("(null)");
	printf("\n");
	printf(" [ Redirection ]:\n");
	if (command->redirection)
		print_redirections(command);
		// print_command_red(command->redirection);
	else
		printf("(null)");
	printf("\n}\n");
}

static void	print_commands_rec(t_ast *parser)
{
	t_node	*node;

	if (!parser)
		return ;
	node = (t_node *)parser->content;
	if (node->type == Simple_Command)
	{
		print_command_template(node->cmd);
		return ;
	}
	print_commands_rec(parser->left);
	print_commands_rec(parser->right);
}
