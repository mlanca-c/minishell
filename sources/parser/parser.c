/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:47:29 by mlanca-c         ###   ########.fr       */
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
	token_files(token_list);
	return (token_list);
}

t_ast	*grammatical_analyser(t_list *token_list)
{
	t_ast		*parser;
	t_token		*token;
	void		*node;

	parser = NULL;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == ASSIGNMENT_WORD)
		{
			node = (t_assign *)get_assignment(&token_list);
			assignment_add_parser(parser, (t_assign *)node);
		}
		// else if (is_token_separator(token->type))
		// {
		// 	node = (t_cmd_t)get_separator(&token_list);
		// 	separator_add_parser(parser, (t_cmd_t)node);
		// }
		// else
		// {
		// 	node = (t_cmd *)get_command(&token_list);
		// 	command_add_parser(parser, (t_cmd *)node);
		// }
	}
	return (parser);
}
