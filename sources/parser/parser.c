/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:15:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:15:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function is the lexical analyser part of the parsing of the shell.
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
