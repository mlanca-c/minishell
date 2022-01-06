/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 13:50:30 by mlanca-c         ###   ########.fr       */
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
	return (token_list);
}

t_parse	*grammatical_analyser(t_list *token_list)
{
	t_parse	*parser;

	parser = (t_parse *)malloc(sizeof(t_parse));
	if (!parser)
		exit_shell();
	parser->type = get_parser_type(token_list);
	parser->cmd = get_parser_cmd(token_list, parser->type);
	print_commands(parser->cmd);
	return (parser);
}

/*
t_parse	*grammatical_analyser(t_list *token_list)
{
	t_parse	*parser;

	parser = (t_parse *)malloc(sizeof(t_parse));
	if (!parser)
		exit_shell();
	parser->type = Simple_Command;
	parser->command = get_parser_command(token_list);
	return (parser);
}

t_cmd	*get_parser_command(t_list *token_list)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		exit_shell();
	cmd->cmd_name = ((t_token *)token_list->content)->text;
	cmd->cmd_arguments = token_list->next;
	return (cmd);
}
*/
