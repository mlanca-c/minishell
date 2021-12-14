/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:05:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/14 12:10:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	signals(void)
{
	struct sigaction	sa_sigint;

	sa_sigint.sa_sigaction = handler_sigint;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		return (perror("SIGINT"));
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (perror("SIGQUIT"));
}
