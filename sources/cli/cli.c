/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/03 18:02:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	cli(void)
{
	char	*line;
	char	*buffer;
	t_ctrl	*controllers;

	signals();
	buffer = "";
	controllers = init_controllers(NULL);
	while (true)
	{
		line = readline(controllers->prompt);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			exit_shell(controllers, E_NULL);
		}
		if (ft_strlen(line) && ft_strcmp(line, buffer))
			add_history(line);
		buffer = line;
		controls(line);
	}
	exit_shell(controllers, E_NULL);
}

/*
*/
void	controls(char *line)
{
	t_ctrl	*controllers;

	if (!line)
		return ;
	controllers = init_controllers(NULL);
	if (controllers->token_list)
		token_free(controllers->token_list);
	controllers->token_list = lexical_analyser(line);
	print_token(controllers->token_list);
}
