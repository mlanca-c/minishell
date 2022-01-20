/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 22:41:17 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

/* zsh-ike promp Macros */
# define ZSH_SHELL	"oh-my-crash"
# define ZSH_PROMPT	"\033[32;1m➜\033[0m "

/* bash-like promp Macros */
# define SHELL		"crash"
# define PROMPT		"crash-1.0$ "

/* cli.c Functions */
void	cli(void);
void	controls(char *line);

#endif /* CLI_H */
