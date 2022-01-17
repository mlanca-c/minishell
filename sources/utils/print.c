/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:09:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 17:52:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_list *token_list)
{
	static char	*type[] = {"word", "assignment_word", "io_number", 	"pipe",
	"less", "great", "dless", "dgreat", "io_file", "and_if", "or_if",
	"left_parentesis", "right_parentesis", NULL};
	t_token		*token;

	printf("Tokens:\n");
	while (token_list)
	{
		token = (t_token *)token_list->content;
		printf("\ttext: %s\n", token->text);
		printf("\ttype: %s\n", type[token->type]);
		token_list = token_list->next;
		printf("\n");
	}
}

void	print_controllers(t_ctrl *controllers)
{
	int	i;

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
	printf("\tparser_tree: %p\n", &controllers->parser);
}

void	print_command(t_cmd *command)
{
	printf("Name: %s\n", command->name);
	printf("Arguments: ");
	while (command->arguments)
	{
		printf("%s ", (char *)command->arguments->content);
		command->arguments = command->arguments->next;
	}
	printf("\n");
	//printf("Redirections: %s\n", command->redirection);
}
