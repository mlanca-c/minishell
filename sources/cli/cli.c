/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/15 17:07:42 by mlanca-c         ###   ########.fr       */
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
		// function name that will be at the bottom of this function and will incaminhar
		// todo os parsing
	}
	rl_clear_history();
}
