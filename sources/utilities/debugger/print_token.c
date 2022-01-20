/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:21:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 20:09:58 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function prints one token */
void	print_token(t_token *token)
{
	static char	*type[] = {"word", "assignment_word", "io_number", 	"pipe",
	"less", "great", "dless", "dgreat", "io_file", "and_if", "or_if",
	"left_parentesis", "right_parentesis", "eof", NULL};

	if (!token)
		return ;
	printf("%s<text: %s\ttype: %s>\n", GREEN, token->text, type[token->type]);
	printf("%s", RESET);
}

/* This function prints the full list of tokens */
void	print_tokens(void)
{
	t_list	*token_list;

	token_list = init_controllers(NULL)->token_list;
	printf("\n\n%s{ Tokens }%s\n", GREEN, RESET);
	while (token_list)
	{
		print_token((t_token *)token_list->content);
		token_list = token_list->next;
	}
}
