/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:08:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 18:09:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This is the main function of the project.
 * It initializes the main variable - (t_ctrl*) controllers - and then calls the
 * function cli() for the shell to start reading commands from user - parse them
 * and execute them.
 * If the program is compiled with --print flag, then controllers->print is set
 * as true and the debugger mode is turned on.
 * If the program is compiled with --oh-my-crash flag, then minishell will
 * present a prompt resembling oh-my-zsh prompt.
 *
 * @param	int		argc	- argument counter.
 * @param	cha-r *argv[]	- command line argument.
 * @param	char *envp[]	- program’s environment variable.
*/
int	main(int argc, char *argv[], char *envp[])
{
	t_ctrl	*controllers;

	init_controllers(envp);
	controllers = init_controllers(NULL);
	if ((argc > 1 && !ft_strncmp(argv[1], "--debug", 7))
		|| (argc > 2 && !ft_strncmp(argv[2], "--debug", 7)))
		controllers->debugger = true;
	if ((argc > 1 && !ft_strncmp(argv[1], "--oh-my-crash", 13))
		|| (argc > 2 && !ft_strncmp(argv[2], "--oh-my-crash", 13)))
	{
		controllers->shell = ZSH_SHELL;
		controllers->prompt = ZSH_PROMPT;
	}
	cli();
	exit_shell();
	return (0);
}
