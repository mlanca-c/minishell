/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:37:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 14:28:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ident(int level);

void	print_command_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}

void	print_command(t_cmd *command)
{
	print_command_lst(command->prefix);
	if (command->name)
		printf("%s ", command->name);
	print_command_lst(command->suffix);
	printf("\n");
}

void	print_command_template(t_cmd *command)
{
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
	printf("}\n");
}

void	print_commands_rec(t_ast *parser)
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

void	print_commands(t_ast *parser)
{
	printf("\n\n%s{ Commands }\n", YELLOW);
	print_commands_rec(parser);
	printf("%s", RESET);
}
