/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/21 16:07:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*generate_prompt(void);

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
	char	*prompt;

	signals();
	buffer = "";
	controllers = init_controllers(NULL);
	if (controllers->debugger)
		print_controllers();
	while (true)
	{
		prompt = generate_prompt();
		line = readline(prompt);
		free(prompt);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			exit_shell();
		}
		if (ft_strlen(line) && ft_strcmp(line, buffer))
			add_history(line);
		buffer = line;
		controls(line);
	}
	exit_shell();
}

char	*generate_prompt(void)
{
	t_ctrl	*controllers;
	char	*prompt;

	controllers = init_controllers(NULL);
	if (!ft_strncmp(controllers->shell, SHELL, ft_strlen(SHELL)))
		return (ft_strdup(controllers->prompt));
	if (!controllers->error)
		prompt =  GREEN "➜ " BCYAN "~ " RESET;
	else
		prompt =  RED "➜ " BCYAN "~ " RESET;
	prompt = ft_strdup(prompt);
	return (prompt);
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
	controllers->token_list = lexer(line);
	controllers->parser_tree = parser();
	if (!controllers->parser_tree)
		exit_shell();
	if (controllers->debugger)
	{
		print_tokens();
		print_parser();
		print_commands(controllers->parser_tree);
	}
	ft_lst_clear(controllers->token_list, free_token);
	free_parser(controllers->parser_tree);
}
