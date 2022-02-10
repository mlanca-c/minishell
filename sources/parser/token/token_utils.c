/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:56:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 10:01:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function gets the next token out of 'line'. */
t_token	*scan_token(int status)
{
	static t_list	*token_list = NULL;
	t_token			*token;
	t_ctrl			*controllers;

	if (status == CLEAR)
	{
		token_list = NULL;
		return (NULL);
	}
	else if (!token_list)
	{
		controllers = scan_controllers(NULL);
		token_list = controllers->token_list;
		return ((t_token *)token_list->content);
	}
	else if (status == NEXT)
	{
		if (!token_list->next)
			return (NULL);
		token_list = token_list->next;
	}
	token = (t_token *)token_list->content;
	return (token);
}

/* This function frees 'token' */
void	free_token(void *token)
{
	free(((t_token *)token)->text);
	free(token);
}
