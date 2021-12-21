/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:12:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/18 20:45:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	*lexer(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] is operator && token[j].type is compatible)
			add_to_token();
		else if (line[i] is operator && token[j].type is not compatible)
			delimit_token(token[j]);
		else if (line[i] is quote)
			add_to_token();
		else if (line[i] is $ (or `))
	}
	delimit_token();
	return (NULL);
}
