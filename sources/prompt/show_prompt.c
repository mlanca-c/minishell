/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:17:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/11 18:41:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	if (signum == SIGINT)
		printf("\n%s", SHELL);
}

/*
*/
void	show_prompt(void)
{
	char				*line_buf;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigint;
	sigaction(SIGINT, &sa_signal, NULL);
	sigaction(SIGQUIT, &sa_signal, NULL);
	while (true)
	{
		line_buf = readline(SHELL);
		if (!line_buf)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(line_buf))
			add_history(line_buf);
		if (!ft_strcmp(line_buf, "exit"))
			break ;
	}
}
