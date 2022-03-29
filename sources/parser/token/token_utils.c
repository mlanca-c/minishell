/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:25:43 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function handles the NEW_LINE token at the end of a line. */
void	token_definition(t_dlist *token_list)
{
	t_token	*token;

	if (!token_list)
		return ;
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->text = ft_strdup("null");
	token->type = NEW_LINE;
	ft_dlst_add_back(&token_list, ft_dlst_new(token));
}
