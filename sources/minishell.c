/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:08:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:51:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This is the main function of the project.
** It initializes the main variable - (t_ctrl*) controllers and then calls the
** function cli() for the shell to start reading commands from user - parse them
** and execute them.
**
** @param	int		argc	- argument counter.
** @param	char *argv[]	- command line argument.
** @param	char *envp[]	- program’s environment variable.
*/
int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	init_controllers(envp);
	cli();
	return (0);
}
