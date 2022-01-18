/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:56:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 01:38:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function gets the next token out of 'line'. */
t_token	*scan_token(int status)
{
	static t_list	*token_list = NULL;
	t_token			*token;
	t_ctrl			*controllers;

	if (!token_list)
	{
		controllers = init_controllers(NULL);
		token_list = controllers->token_list;
	}
	else if (status == NEXT)
	{
		if (!token_list->next)
			return (NULL);
		return ((t_token *)token_list->next->content);
	}
	token_list = token_list->next;
	token = (t_token *)token_list->content;
	return (token);
}

/* This function frees 'token' */
void	free_token(void *token)
{
	free(((t_token *)token)->text);
	free(token);
}
