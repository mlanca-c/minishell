/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/25 10:03:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function is the lexical analyser of the shell. */
t_list	*lexer(char *line)
{
	t_list	*token_list;
	int		i;

	token_list = NULL;
	i = 0;
	while (line[i])
		i += token_recognition(&token_list, &line[i]);
	token_definition(token_list);
	return (token_list);
}

/* This function is the grammatical analyser of the shell. */
t_ast	*parser(void)
{
	t_ast	*ast;

	scan_token(NEXT);
	ast = parse_list();
	if (scan_token(GET)->type != NEW_LINE)
	{
		printf("Expected end of string but got \"%s\"\n", scan_token(GET)->text);
		return (NULL);
	}
	scan_token(CLEAR);
	return (ast);
}
