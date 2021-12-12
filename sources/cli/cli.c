/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:55:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/12 14:09:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	cli(void)
{
	char	*line_buf;

	signals();
	while (true)
	{
		line_buf = readline(SHELL);
		if (!line_buf || !ft_strcmp(line_buf, "exit"))
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(line_buf))
			add_history(line_buf);
		//lexer(line_buf);
	}
}
