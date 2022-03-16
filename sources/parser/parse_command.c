/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/05 21:52:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast	*new_command(void);

/* This function handles the parsing of WORD tokens */
t_ast	*parse_command(void)
{
	t_ast	*a;

	a = NULL;
	if (scan_token(GET)->type == WORD || (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT))
		a = new_command();
	else if (scan_token(GET)->type == L_PAR)
	{
		scan_token(NEXT);
		a = parse_list();
		if (!a)
			return (NULL);
		if (scan_token(GET)->type == R_PAR)
		{
			scan_token(NEXT);
			return (a);
		}
		else
			return (NULL);
	}
	else if (scan_token(GET)->type == NEW_LINE)
		return (NULL);
	return (a);
}

/* This function creates a new node for Simple Commands */
static t_ast	*new_command(void)
{
	t_ast	*ast;
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	new_node->type = Simple_Command;
	new_node->cmd = command();
	ast = ft_ast_new((void *)new_node);
	return (ast);
}
