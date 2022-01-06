/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:39:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 13:50:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function returns the type of command.
 * Its not returning the type List yet (Bonus part).
*/
t_cmd_t	get_parser_type(t_list *token_list)
{
	t_token	*token;
	bool	pipeline;

	pipeline = false;
	while (token_list)
	{
		token = (t_token *)(token_list->content);
		if (token == PIPE)
			return (Pipeline);
		token_list = token_list->next;
	}
	return (Simple_Command);
}

t_list	*get_parser_command(t_list *token_list, t_cmd_t type)
{
	t_list	*parser_cmd;
	t_list	*temp;
	t_token	*token;
	// t_cmd	*cmd;

	temp = token_list;
	while (token_list)
	{
		token = (t_token *)(token_list->content);
		if (token == PIPE)
			ft_lst_add_back(&parser_cmd, ft_lst_new(get_new_command(token_list)));
		token_list = token_list->next;
	}
	return (parser_cmd);
}

t_cmd	*get_new_command(t_list *token_list, int end)
{}
