/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/05 21:52:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast	*new_pipeline(t_ast *a, t_ast *b);

/* This function handles the parsing of PIPE tokens */
t_ast	*parse_pipe(void)
{
	t_ast	*a;
	t_ast	*b;

	a = parse_command();
	while (true)
	{
		if (scan_token(GET)->type == PIPE)
		{
			scan_token(NEXT);
			b = parse_command();
			a = new_pipeline(a, b);
		}
		else
			return (a);
	}
	return (NULL);
}

static t_ast	*new_pipeline(t_ast *a, t_ast *b)
{
	t_ast	*ast;
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	new_node->type = Pipeline;
	ast = ft_ast_new((void *)new_node);
	ft_ast_add_left(&ast, a);
	ft_ast_add_right(&ast, b);
	return (ast);
}
