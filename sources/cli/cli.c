/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:55:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/12 18:41:17 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	cli(void)
{
	char	*line;
	char	*buffer;

	signals();
	buffer = "";
	while (true)
	{
		line = readline(SHELL);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(line) && ft_strcmp(line, buffer))
			add_history(line);
		buffer = line;
	}
}
