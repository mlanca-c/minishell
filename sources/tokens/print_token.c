/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:09:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 16:10:20 by mlanca-c         ###   ########.fr       */
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

