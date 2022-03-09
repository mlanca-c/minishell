/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:08:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/09 20:47:31 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* main function of the program */
int	main(int argc, char *argv[], char *envp[])
{
	t_ctrl	*controllers;

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
	exit_shell(SUCCESS);
	return (0);
}
