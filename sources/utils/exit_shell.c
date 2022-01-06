/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 13:52:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function focuses in freeing everything and exiting the program.
*/
void	exit_shell(void)
{
/*	int		i;
	t_ctrl	*controllers;

	controllers = init_controllers(NULL);
	rl_clear_history();
	if (!controllers)
		exit(EXIT_SUCCESS);
	if (status == E_NULL)
	{
		free(controllers->home);
		i = 0;
		while (controllers->path[i])
			free(controllers->path[i++]);
		token_free(controllers->token_list);
		free(controllers);
		exit(EXIT_SUCCESS);
	}*/
	exit(EXIT_FAILURE);
}

/*
 * This function frees the (t_list *) list of tokens.
*/
void	token_free(t_list *token_list)
{
	t_token	*token;
	t_list	*temp;

	if (!token_list)
		return ;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		free(token->text);
		free(token);
		temp = token_list;
		token_list = token_list->next;
		free(temp);
	}
}
