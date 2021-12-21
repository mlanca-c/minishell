/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/18 19:03:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line)
{
	void	*token;

	if (!line)
		return ;
	/*
	if (controllers->here_doc)
		here_doc(line);
	else
		lexer(line);
	*/
	token = lexer(line);
}
