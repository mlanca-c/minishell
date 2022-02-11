/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 21:33:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function reads a line from the shell and then calls controls() */
void	cli(void)
{
	char	*line;
	char	*prompt;

	signals();
	if (scan_controllers(NULL)->debugger)
		print_controllers();
	while (true)
	{
		prompt = prompt_generator();
		line = readline(prompt);
		free(prompt);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			exit_shell();
		}
		if (!ft_strlen(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		controls(line);
		free(line);
	}
}

/* This function represents the bridge between the parsing and execution */
void	controls(char *line)
{
	t_ctrl	*controllers;

	if (!line)
		return ;
	controllers = scan_controllers(NULL);
	if (controllers->debugger)
		print_controllers();
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
	resrap();
	if (controllers->debugger)
		print_commands(controllers->parser_tree);
	ft_ast_clear(controllers->parser_tree, free_node);
	ft_lst_clear(controllers->token_list, free_token);
}

/* This function generates a prompt according from controllers->prompt */
char	*prompt_generator(void)
{
	t_ctrl	*controllers;
	char	*prompt;
	char	*f;

	controllers = scan_controllers(NULL);
	if (!ft_strcmp(controllers->shell, SHELL))
		return (ft_strdup(controllers->prompt));
	if (scan_error(NULL))
		prompt = RED "➜  " BCYAN;
	else
		prompt = GREEN "➜  " BCYAN;
	prompt = ft_strjoin(prompt, scan_directory());
	f = prompt;
	prompt = ft_strjoin(prompt, " " RESET);
	free(f);
	return (prompt);
}
