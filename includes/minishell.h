/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:22:55 by josantos          #+#    #+#             */
/*   Updated: 2022/03/31 17:28:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* External Functions */
# include <term.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <curses.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>

/* general headers */
# include "color.h"
# include "libft.h"
# include "signals.h"
# include "types.h"
# include "controllers.h"
# include "debugger.h"
# include "exit_shell.h"
# include "cli.h"
# include "parser.h"
# include "execution.h"
# include "word_expansion.h"
# include "builtins.h"

#endif /* MINISHELL_H */
