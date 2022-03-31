/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sigint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:11:29 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 13:54:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	handler_sigint(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	sa(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	else if (signum == SIGQUIT)
		printf("Quit: %d\n", signum);
}

void	sigint(int signum)
{
	(void)signum;
	printf("\n");
}

void	sigquit(int signum)
{
	printf("QUIT:%d\n", signum);
}
