/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:29:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 12:13:23 by mlanca-c         ###   ########.fr       */
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

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->text = ft_substr(text, 0, end);
	token->type = token_assignment(token->text);
	return (token);
}

/*
 * This function assigns a type for each token. Either an operator or a WORD
*/
t_token_t	token_assignment(char *text)
{
	static char	*type[] = {"|", ">", "<", ">>", "<<", "io_file", "&&", "||",
		"(", ")", NULL};
	int			i;

	i = 0;
	while (type[i])
	{
		if (ft_strcmp(type[i], text) == 0)
			return (i + 3);
		i++;
	}
	return (WORD);
}

/*
 * This function handles the token IO_FILE IO_NUMBER and ASSIGNMENT_WORD.
*/
void	token_definition(t_list *token_list)
{
	t_token	*token;
	// t_token	*p_token;
	//
	// while (token_list->next)
	// {
	// 	p_token = (t_token *)token_list->content;
	// 	token_list = token_list->next;
	// 	token = (t_token *)token_list->content;
	// 	if (token->type == WORD && ft_str_isnumeric(token->text)
	// 		&& (p_token->type == LESS || p_token->type == GREAT))
	// 		token->type = IO_NUMBER;
	// 	else if (token->type == WORD && (p_token->type == LESS
	// 			|| p_token->type == GREAT || p_token->type == DLESS
	// 			|| p_token->type == DGREAT))
	// 		token->type = IO_FILE;
	// 	if (p_token->type == WORD && ft_strchr(p_token->text, '='))
	// 		p_token->type = ASSIGNMENT_WORD;
	// 	if (token->type == WORD && ft_strchr(token->text, '='))
	// 		token->type = ASSIGNMENT_WORD;
	// }
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->text = ft_strdup("null");
	token->type = NEW_LINE;
	ft_lst_add_back(&token_list, ft_lst_new(token));
}
