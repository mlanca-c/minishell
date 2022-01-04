/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:22:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:16:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/* signals.c Function */
void	signals(void);

/* handler_sigint.c Function */
void	handler_sigint(int signum, siginfo_t *info, void *context);

#endif /* SIGNALS_H */
