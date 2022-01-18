/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 00:58:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_pipe(void)
{
	t_ast	*a;
	t_ast	*b;

	printf("parse_pipe\n");
	a = parse_list();
	while (true)
	{
		if (scan_token(NEXT)->type == PIPE)
		{
			scan_token(UPDATE);
			b = parse_list();
			a = new_pipe(a, b);
		}
		else
			return (a);
	}
	return (NULL);
}

t_ast	*new_pipe(t_ast *a, t_ast *b)
{
	t_ast	*root;

	root = ft_ast_new(ft_strdup("Pipeline"));
	root->left = a;
	root->right = b;
	return (root);
}
