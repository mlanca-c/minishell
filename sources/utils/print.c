/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:09:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 14:00:24 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_list *token_list)
{
	t_token	*token;

	printf("Tokens:\n");
	while (token_list)
	{
		token = (t_token *)token_list->content;
		printf("\ttext: %s\n", token->text);
		if (token->type == WORD)
			printf("\ttype: WORD\n");
		else if (token->type == ASSIGNMENT_WORD)
			printf("\ttype: ASSIGNMENT_WORD\n");
		else if (token->type == NEWLINE)
			printf("\ttype: NEWLINE\n");
		else if (token->type == IO_NUMBER)
			printf("\ttype: IO_NUMBER\n");
		else if (token->type == PIPE)
			printf("\ttype: PIPE\n");
		else if (token->type == LESS)
			printf("\ttype: LESS\n");
		else if (token->type == GREAT)
			printf("\ttype: GREAT\n");
		else if (token->type == AND_IF)
			printf("\ttype: AND_IF\n");
		else if (token->type == OR_IF)
			printf("\ttype: OR_IF\n");
		else if (token->type == DLESS)
			printf("\ttype: DLESS\n");
		else if (token->type == DGREAT)
			printf("\ttype: DGREAT\n");
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
	printf("\ttoken_list: %p\n", &controllers->token_list);
	i = 0;
	printf("\tpath:\n");
	while (controllers->path[i])
	{
		printf("\t\t- %s\n", controllers->path[i]);
		i++;
	}
	printf("\tHome: %s\n", controllers->home);
	i = 0;
	while (controllers->envp[i])
	{
		printf("%s\n", controllers->envp[i]->content);
		i++;
	}
	
}
