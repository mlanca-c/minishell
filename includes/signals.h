/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:22:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/01 12:39:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/* signals.c Function */
void	signals(void);
void	signals_child(void);
void	signals_heredoc(void);

/* handler_sigint.c Function */
void	handler_sigint(int signum);
void	handler_child(int signum);
void	handler_heredoc(int signum);

#endif /* SIGNALS_H */
