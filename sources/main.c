/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:22:15 by josantos          #+#    #+#             */
/*   Updated: 2021/12/10 16:00:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_shell(void)
{
	char	*cmd_buf;
	
	cmd_buf = readline("crash-1.0$ ");
	if (ft_strlen(cmd_buf) > 0)
		add_history(cmd_buf);
}

void	shell_launch(void)
{
	pid_t	pid;
	
	pid = fork();
	if (pid < 0)
		perror("error forking");
	if (pid == 0)
		child_process(pid);
	else
		parent_process(pid);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;

	//parcing//
	while (true)
	{
		start_shell();
		shell_launch();
	}
}