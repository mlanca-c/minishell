/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:29:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			token_quotes(char *line);
static t_token		*token_update(char *text, int end);
static t_token_t	token_assignment(char *text);
static int			token_word(char *line);

/* This function does token recognition */
int	token_recognition(t_dlist **token_list, char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	if (ft_strchr("|><&", line[i]))
		while (line[i] && ft_strchr("|><&", line[i]))
			i++;
	else if (ft_strchr("()", line[i]))
		i++;
	else if (ft_strchr("\'\"", line[i]))
		i += token_quotes(&line[i]);
	else
		i += token_word(line);
	token = token_update(line, i);
	if (token)
		ft_dlst_add_back(token_list, ft_dlst_new(token));
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

/* This function handles quoting. */
static int	token_quotes(char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = line[i];
	if (line[i++] == quote)
	{
		while (line[i] != quote)
			i++;
		i++;
	}
	return (i);
}

/* This function creates tokens - nodes of the t_dlist* token_list. */
static t_token	*token_update(char *text, int end)
{
	t_token	*token;

	if (ft_isspace(text[0]))
		return (NULL);
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->text = ft_substr(text, 0, end);
	token->type = token_assignment(token->text);
	return (token);
}

/* This function assigns a type for each token. Either an operator or a WORD */
static t_token_t	token_assignment(char *text)
{
	static char	*type[] = {"|", "<", ">", "<<", ">>", "&&", "||",
		"(", ")", NULL};
	int			i;

	i = 0;
	while (type[i])
	{
		if (ft_strcmp(type[i], text) == 0)
			return (i + 1);
		i++;
	}
	return (WORD);
}

/* This function handles word type tokens */
static int	token_word(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_strchr("|><&()\'\"", line[i])
		&& !ft_isspace(line[i]))
	{
		if (line[i] == '=' && ft_strchr("\'\"", line[i + 1]))
			i += token_quotes(&line[i + 1]);
		i++;
	}
	return (i);
}
