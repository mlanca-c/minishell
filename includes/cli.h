/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 11:07:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

/* zsh-ike promp Macros */
# define ZSH_SHELL	"oh-my-crash"
# define ZSH_PROMPT	"➜ "

/* bash-like promp Macros */
# define SHELL		"crash"
# define PROMPT		"crash-1.0$ "

/* cli.c Functions */
void	cli(void);
void	controls(char *line);

#endif /* CLI_H */
