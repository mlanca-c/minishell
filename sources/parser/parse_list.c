/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:48:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 00:59:10 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_list(void)
{
	t_ast	*a;
	t_ast	*b;

	printf("parse_list\n");
	a = parse_paren();
	while (true)
	{
		if (scan_token(NEXT)->type == AND_IF)
		{
			scan_token(UPDATE);
			b = parse_paren();
			a = new_and_list(a, b);
		}
		else if (scan_token(NEXT)->type == OR_IF)
		{
			scan_token(UPDATE);
			b = parse_paren();
			a = new_or_list(a, b);
		}
		else
			return (a);
	}
	return (NULL);
}

t_ast	*new_or_list(t_ast *a, t_ast *b)
{
	t_ast	*root;

	root = ft_ast_new(ft_strdup("And"));
	root->left = a;
	root->right = b;
	return (root);
}

t_ast	*new_and_list(t_ast *a, t_ast *b)
{
	t_ast	*root;

	root = ft_ast_new(ft_strdup("Or"));
	root->left = a;
	root->right = b;
	return (root);
}
