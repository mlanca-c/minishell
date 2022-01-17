/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 19:21:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function is the lexical analyser part of the parsing of the shell.
*/
t_list	*lexical_analyser(char *line)
{
	int		i;
	t_list	*token_list;

	i = 0;
	token_list = NULL;
	while (line[i])
		i += token_recognition(&token_list, &line[i]);
	token_definition(token_list);
	return (token_list);
}

t_ast	*grammatical_analyser(t_list *token_list)
{
	t_ast		*parser;
	t_ast		*node;
	t_token		*token;

	parser = NULL;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (is_token_separator(token->type))
		{
			node = get_separator(&token_list);
			parser = separator_add_parser(&node, parser);
		}
		else
		{
			node = get_command(&token_list);
			command_add_parser(node, &parser);
		}
		ft_ast_print(parser);
	}
	return (parser);
}
