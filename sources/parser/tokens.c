/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:22:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:00:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function does the token recognition
*/
int	token_recognition(t_list **token_list, char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	if (ft_isoperator(line[i]))
		while (line[i] && ft_isoperator(line[i]) && !ft_isspace(line[i]))
			i++;
	else if (ft_strchr("\'\"", line[i]))
		i += token_quotes(&line[i]);
	else
		while (line[i] && !ft_isoperator(line[i]) && !ft_isspace(line[i]))
			i++;
	token = token_update(line, i);
	if (token)
		ft_lst_add_back(token_list, ft_lst_new(token));
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

/*
 * This function handles quoting.
*/
int	token_quotes(char *line)
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

/*
 * This function updates tokens - nodes of the t_list* token_list.
*/
t_token	*token_update(char *text, int end)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->text = ft_substr(text, 0, end);
	token->type = token_assignment(token->text);
	return (token);
}

/*
 * This function assigns a type for each token.
*/
t_token_t	token_assignment(char *text)
{
	static char	*type[] = {"word", "assignment_word", "io_number",
	"|", ">", "<", ">>", "<<", "&&", "||", NULL};
	int			i;

	if (ft_str_isnumeric(text))
		return (IO_NUMBER);
	i = 0;
	while (type[i])
	{
		if (ft_strcmp(type[i], text) == 0)
			return (i);
		i++;
	}
	if (ft_strchr(text, '='))
		return (ASSIGNMENT_WORD);
	else
		return (WORD);
}
