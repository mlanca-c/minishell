/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:04:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 16:09:34 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
t_list	*lexical_analyser(char *line)
{
	int		i;
	t_list	*token_list;

	i = 0;
	token_list = NULL;
	while (line[i])
		i += token_recognition(&token_list, &line[i]);
	return (token_list);
}
