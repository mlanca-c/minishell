/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 16:47:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*new_command(void);

/*
 * I want to return an ast rooted in Simple_Command
 * This only happens with WORD type tokens.
 *
 * For now this function returns a ast node Simple_Command and token_list is
 * behind all those word type tokens
*/
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

t_ast	*new_command(void)
{
	t_ast	*a;
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	cmd->prefix = command_prefix();
	if (scan_token(GET)->type == WORD)
	{
		cmd->name = ft_strdup(scan_token(GET)->text);
		scan_token(NEXT);
	}
	cmd->suffix = command_suffix();
	a = ft_ast_new((void *)Simple_Command);
	ft_ast_add_left(&a, ft_ast_new(cmd));
	return (a);
}
