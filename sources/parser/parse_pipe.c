/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 11:15:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*new_pipeline(t_ast *a, t_ast *b);

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

t_ast	*new_pipeline(t_ast *a, t_ast *b)
{
	t_ast	*ast;

	ast = ft_ast_new((void *)Pipeline);
	ft_ast_add_left(&ast, a);
	ft_ast_add_right(&ast, b);
	return (ast);
}
