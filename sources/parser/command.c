/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:36:05 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:09:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		add_list(t_dlist **prefix, char *text);
static t_dlist	*command_suffix(void);
static t_dlist	*command_prefix(void);
static t_dlist	*scan_redirection(t_token_t type, char *file);

t_cmd	*command(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		exit_shell();
	cmd->prefix = command_prefix();
	if (scan_token(GET)->type == WORD)
	{
		cmd->name = ft_strdup(scan_token(GET)->text);
		scan_token(NEXT);
	}
	cmd->suffix = command_suffix();
	cmd->redirection = scan_redirection(0, NULL);
	return (cmd);
}

static t_dlist	*scan_redirection(t_token_t type, char *file)
{
	static t_dlist	*lst = NULL;
	t_dlist			*temp;
	t_red			*redirection;

	if (!file)
	{
		temp = lst;
		lst = NULL;
		return (temp);
	}
	redirection = ft_calloc(sizeof(t_red), 1);
	if (!redirection)
		return (NULL);
	redirection->io_file = ft_strdup(file);
	redirection->io_type = type;
	ft_dlst_add_back(&lst, ft_dlst_new(redirection));
	return (NULL);
}

static t_dlist	*command_suffix(void)
{
	t_dlist		*suffix;
	t_token_t	type;

	suffix = NULL;
	while (true)
	{
		if (scan_token(GET)->type == WORD)
			add_list(&suffix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			type = scan_token(GET)->type;
			scan_token(NEXT);
			scan_redirection(type, scan_token(GET)->text);
		}
		else
			return (suffix);
		scan_token(NEXT);
	}
	return (NULL);
}

static t_dlist	*command_prefix(void)
{
	t_dlist		*prefix;
	t_token_t	type;

	prefix = NULL;
	while (true)
	{
		if (ft_strchr(scan_token(GET)->text, '='))
			add_list(&prefix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			type = scan_token(GET)->type;
			scan_token(NEXT);
			scan_redirection(type, scan_token(GET)->text);
		}
		else
			return (prefix);
		scan_token(NEXT);
	}
	return (NULL);
}

static void	add_list(t_dlist **prefix, char *text)
{
	char	*str;

	str = ft_strdup(text);
	ft_dlst_add_back(prefix, ft_dlst_new(str));
}
