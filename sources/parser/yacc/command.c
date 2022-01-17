/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:01:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 19:26:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function converts a Simple Command from the token_list
*/
t_ast	*get_command(t_list **token_list)
{
	t_list	*list;
	t_token	*token;

	list = *token_list;
	while (list)
	{
		token = (t_token *)list->content;
		if (is_token_separator(token->type))
			break ;
		list = list->next;
	}
	*token_list = list;
	return (ft_ast_new(ft_strdup("Simple Command")));
}

/*
 * This function adds a Simple Command to an AST
*/
void	command_add_parser(t_ast *node, t_ast **parser)
{
	t_ast	*temp;

	temp = *parser;
	if (!parser || !node)
	{
		*parser = node;
		return ;
	}
	if (!temp->right)
	{
		temp->right = node;
		return ;
	}
	command_add_parser(node, &(temp->left));
	command_add_parser(node, &(temp->right));
}
