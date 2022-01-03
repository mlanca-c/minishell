/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:41:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/03 17:44:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

/* Prompt realted Macros */
# ifndef ZSH
#  define ZSH	10
# endif /* ZSH */

# if ZSH == 1
#  define SHELL		"zcrash"
#  define PROMPT	"\033[32;1m➜\033[0m "
# else
#  define SHELL		"crash"
#  define PROMPT	"crash-1.0$ "
# endif /* ZSH */

/* cli.c Functions */
void	cli(void);
void	controls(char *line);

#endif /* CLI_H */
