/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:08:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 19:03:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_token_separator(t_token_t type)
{
	if (type == PIPE || type == AND_IF || type == OR_IF || type == L_PAR
		|| type == R_PAR)
		return (true);
	return (false);
}

t_ast	*get_separator(t_list **token_list)
{
	static char	*type[] = {"Pipeline", "And", "Or", NULL};
	t_token		*token;
	int			i;
	t_ast		*root;

	token = (t_token *)(*token_list)->content;
	if (token->type == PIPE)
		i = 0;
	else if (token->type == AND_IF)
		i = 1;
	else if (token->type == OR_IF)
		i = 2;
	root = NULL;
	ft_ast_add_left(&root, ft_ast_new(ft_strdup(type[i])));
	*token_list = (*token_list)->next;
	return (root);
}

/*
 * Command Types are added as the rightmost node up (root)
*/
t_ast	*separator_add_parser(t_ast **node, t_ast *parser)
{
	if (parser)
		(*node)->left = parser;
	return (*node);
}
