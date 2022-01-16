/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:06:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:58:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str);

char	*get_value(char *str);

/*
*/
t_assign	*get_assignment(t_list **token_list)
{
	t_assign	*assignment;
	t_token		*token;

	assignment = (t_assign *)ft_calloc(1, sizeof(t_assign));
	if (!assignment)
		exit_shell();
	token = (t_token *)(*token_list)->content;
	assignment->name = get_name(token->text);
	assignment->value = get_value(token->text);
	*token_list = (*token_list)->next;
	return (assignment);
}

void	assignment_add_parser(t_ast *parser, t_assign *node)
{
	t_ast	*root;

	root = NULL;
	ft_ast_add_left(&root, ft_ast_new(ft_strdup("Assignment Word")));
	ft_ast_add_left(&root, ft_ast_new(ft_strdup(node->name)));
	ft_ast_add_right(&root, ft_ast_new(ft_strdup(node->value)));
	free_assignment(node);
	// if !Simple Commnad create and add. Else add to last SC.
	ft_ast_print(parser);
}

char	*get_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] && str[i - 1] != '=')
		i++;
	name = (char *)ft_calloc(i + 1, sizeof(char));
	if (!name)
		exit_shell();
	i = 0;
	while (str[i])
	{
		name[i] = str[i];
		i++;
		if (str[i - 1] == '=')
			break ;
	}
	return (name);
}

char	*get_value(char *str)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i - 1] != '=')
		i++;
	value = (char *)ft_calloc(ft_strlen(str) - i, sizeof(char));
	if (!value)
		exit_shell();
	j = 0;
	while (str[i + j])
	{
		value[j] = str[i + j];
		j++;
	}
	return (value);
}
