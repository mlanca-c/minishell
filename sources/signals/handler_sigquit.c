/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sigquit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:10:11 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/12 14:17:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*/
void	handler_sigquit(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	printf("\b\b  \b\b");
}
