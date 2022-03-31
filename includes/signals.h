/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:22:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 13:55:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/* signals.c Function */
void	signals(void);

/* handler_sigint.c Function */
void	handler_sigint(int signum, siginfo_t *info, void *context);
void	sa(int signum);
void	sigint(int signum);
void	sigquit(int signum);

#endif /* SIGNALS_H */
