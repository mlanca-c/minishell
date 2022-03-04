/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_minishell.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 18:34:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_MINISHELL_H
# define TESTER_MINISHELL_H

/* include your project header(s) */
/* Here */
# include "minishell.h"

# define YAY	0
# define NAY	1

# define _SUCCESS	"["GREEN" ok "RESET"]\n"
# define _FAILURE	"["RED" ko "RESET"]"
# define _INFO		"["BLUE" %s "RESET"]: "
# define _TEST		BLUE"%-120s "RESET"%s"

/* Tester functions mandatory prototype */
/* (do not change) */
typedef int(*test_fn)(void);

/* Tester Functions */
int	test_scan_controllers(void);
int	test_scan_error(void);
int	test_scan_envp(void);
int	test_scan_path(void);
int	test_scan_directory(void);
int	test_controllers_get_envp(void);

int	test_tilde_expansion(void);
int	test_variable_expansion(void);
int	test_quote_removal(void);
int	test_filename_expansion(void);

int	test_cd(void);
int	test_echo(void);
int	test_env(void);
int	test_export(void);
int	test_pwd(void);

#endif /* TESTER_MINISHELL_H */
