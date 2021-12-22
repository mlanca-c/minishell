/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 16:43:36 by mlanca-c         ###   ########.fr       */
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
			//return (exit_function());
			return ;
		}
		if (ft_strlen(line) && ft_strcmp(line, buffer))
			add_history(line);
		buffer = line;
		controls(line);
	}
	rl_clear_history();
	//exit_function();
}

/*
*/
void	controls(char *line)
{
	if (!line)
		return ;
	lexical_analyser(line);
}
