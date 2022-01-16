/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:01:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:21:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_cmd		*get_command(t_list **token_list)
// {
// }

// void		command_add_parser(t_ast *parser, t_cmd *node)
// {
// }

/*
 * This function creates a command (t_cmd *) type of variable. This command will
 * be one of the leafs of the abstract syntax tree.
t_cmd	*get_command(t_list **token_list)
{
	t_cmd	*command;
	t_token	*token;
	t_list	*temp;

	command = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!command)
		exit_shell();
	temp = *token_list;
	while (temp)
	{
		token = (t_token *)temp->content;
		if (token->type != WORD)
			break ;
		if (!command->name)
			command->name = ft_strdup(token->text);
		else
			ft_lst_add_back(&command->arguments,
				ft_lst_new(ft_strdup(token->text)));
		temp = temp->next;
	}
	*token_list = temp;
	return (command);
}

t_cmd_t	get_separator(t_list **token_list)
{
	t_token	*token;

	token = (t_token *)(*token_list)->content;
	*token_list = (*token_list)->next;
	if (token->type == PIPE)
		return (Pipeline);
 	else if (token->type == AND_IF)
		return (And_List);
	else if (token->type == OR_IF)
		return (Or_List);
	return (Simple_Command);
}
*/
