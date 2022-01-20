/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:21:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 19:31:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*new_list_and(t_ast *a, t_ast *b);
t_ast	*new_list_or(t_ast *a, t_ast *b);

t_ast		*parse_list(void)
{
	t_ast	*a;
	t_ast	*b;

	a = parse_pipe();
	while (true)
	{
		if (scan_token(GET)->type == AND_IF)
		{
			scan_token(NEXT);
			b = parse_pipe();
			a = new_list_and(a, b);
		}
		else if (scan_token(GET)->type == OR_IF)
		{
			scan_token(NEXT);
			b = parse_pipe();
			a = new_list_or(a, b);
		}
		else
			return (a);
	}
	return (NULL);
}

t_ast	*new_list_and(t_ast *a, t_ast *b)
{
	t_ast	*ast;
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	new_node->type = And_List;
	ast = ft_ast_new((void *)new_node);
	ft_ast_add_left(&ast, a);
	ft_ast_add_right(&ast, b);
	return (ast);
}

t_ast	*new_list_or(t_ast *a, t_ast *b)
{
	t_ast	*ast;
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	new_node->type = Or_List;
	ast = ft_ast_new((void *)new_node);
	ft_ast_add_left(&ast, a);
	ft_ast_add_right(&ast, b);
	return (ast);
}
