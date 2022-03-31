/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:08:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 15:24:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* main function of the program */
int	main(int argc, char *argv[], char *envp[])
{
	t_ctrl			*controllers;
	// struct termios	t;

	// tcgetattr(0, &t);
	// t.c_lflag &= ~ECHOCTL;
	// tcsetattr(0, TCSANOW, &t);
	controllers = scan_controllers(envp);
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
