/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/24 19:21:28 by mlanca-c         ###   ########.fr       */
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
	char	*prompt;

	signals();
	buffer = "";
	if (init_controllers(NULL)->debugger)
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
	if (!controllers->token_list)
		exit_shell();
	if (controllers->debugger)
		print_tokens();
	controllers->parser_tree = parser();
	if (!controllers->parser_tree)
		exit_shell();
	if (controllers->debugger)
		print_parser();
	execution();
	ft_lst_clear(controllers->token_list, free_token);
	ft_ast_clear(controllers->parser_tree, free_node);
}

/* This function returns the last folder from controllers->directory */
char	*directory(void)
{
	int		i;
	char	*directory;
	char	**split;

	directory = init_controllers(NULL)->directory;
	split = ft_split(directory, '/');
	i = 0;
	while (split[i])
		i++;
	i--;
	directory = ft_strjoin(split[i], " " RESET);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (directory);
}

/* This function generates a prompt according from controllers->prompt */
char	*generate_prompt(void)
{
	t_ctrl	*controllers;
	char	*prompt;
	char	*f;

	controllers = init_controllers(NULL);
	if (!ft_strcmp(controllers->shell, SHELL))
		return (ft_strdup(controllers->prompt));
	if (find_error())
		prompt = RED "➜  " BCYAN;
	else
		prompt = GREEN "➜  " BCYAN;
	f = directory();
	prompt = ft_strjoin(prompt, f);
	free(f);
	return (prompt);
}
