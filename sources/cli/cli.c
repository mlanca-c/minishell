/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 12:15:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * cli stands for command line interface, and that's what this function
 * represents. It reads a line from the shell and then calls the controls()
 * function for each line it reads to them parse the commands and execute them.
 * Besides that it handles signals() and the history of the user's commands.
 * After the shell is exited, then the cli() calls the exit_shell() function for
 * the program to end with no leaks.
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
			exit_shell(E_NULL);
		}
		if (ft_strlen(line) && ft_strcmp(line, buffer))
			add_history(line);
		buffer = line;
		controls(line);
	}
	exit_shell(E_NULL);
}

/*
 * This function represents the bridge between the parsing of a line and the
 * execution of the commands resulting in that line being parsed.
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
