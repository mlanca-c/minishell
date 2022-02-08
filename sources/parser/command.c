/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:36:05 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 14:30:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_list(t_list **prefix, char *text);

t_cmd	*command(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	cmd->prefix = command_prefix();
	if (scan_token(GET)->type == WORD)
	{
		cmd->name = ft_strdup(scan_token(GET)->text);
		scan_token(NEXT);
	}
	cmd->suffix = command_suffix();
	return (cmd);
}

t_list	*command_suffix(void)
{
	t_list	*suffix;

	suffix = NULL;
	while (true)
	{
		if (scan_token(GET)->type == WORD)
			add_list(&suffix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			add_list(&suffix, scan_token(GET)->text);
			scan_token(NEXT);
			add_list(&suffix, scan_token(GET)->text);
		}
		else
			return (suffix);
		scan_token(NEXT);
	}
	return (NULL);
}

t_list	*command_prefix(void)
{
	t_list	*prefix;

	prefix = NULL;
	while (true)
	{
		if (ft_strchr(scan_token(GET)->text, '='))
			add_list(&prefix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			add_list(&prefix, scan_token(GET)->text);
			scan_token(NEXT);
			add_list(&prefix, scan_token(GET)->text);
		}
		else
			return (prefix);
		scan_token(NEXT);
	}
	return (NULL);
}

void	add_list(t_list **prefix, char *text)
{
	char	*str;

	str = ft_strdup(text);
	ft_lst_add_back(prefix, ft_lst_new(str));
}
