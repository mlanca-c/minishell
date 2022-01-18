/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 01:41:46 by mlanca-c         ###   ########.fr       */
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

/*
 * This function is the lexical analyser part of the parsing of the shell.
*/
t_ast	*parser(void)
{
	t_ast	*ast;

	scan_token(INIT);
	ast = parse_pipe();
	printf("a:\n"); ft_ast_print(ast);
	if (scan_token(GET)->type != NEW_LINE)
		exit_shell();
	return (ast);
}
