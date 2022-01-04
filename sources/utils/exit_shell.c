/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:46:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function focuses in freeing everything and exiting the program.
*/
void	exit_shell(void)
{
	exit(EXIT_FAILURE);
}

/*
 * This function frees the (t_list *) list of tokens.
*/
void	free_token(t_list *token_list)
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
