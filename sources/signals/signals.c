/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:05:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/13 15:41:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sa_sigint.sa_handler = 0;
	sa_sigint.sa_flags = SA_SIGINFO;
	sa_sigint.sa_mask = block_mask;
	sa_sigint.sa_sigaction = handler_sigint;
	sa_sigquit.sa_handler = 0;
	sa_sigquit.sa_flags = SA_SIGINFO;
	sa_sigquit.sa_mask = block_mask;
	sa_sigquit.sa_sigaction = handler_sigquit;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		return (perror("SIGINT"));
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		return (perror("SIGQUIT"));
}
