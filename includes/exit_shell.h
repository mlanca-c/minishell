/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 15:28:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_SHELL_H
# define EXIT_SHELL_H

/* exit_shell.c Functions */
void	exit_shell(void);
void	free_controllers(t_ctrl *controllers);
void	free_node(void *ast_node);
void	free_command(void *cmd);
void	free_token(void *token);
void	free_redirection(void *red);
void	free_parser(t_ast *parser);

/* error messages Functions */

void	process_err(char *argv, char *message);
void	cd_err(t_cmd *command, char *message);
void	open_err(char *file, char *message);
void	path_err(char *argv, char *message);
void	builtin_err(t_cmd *command, char *message);

/* error.c Functions */
void	handle_error(t_cmd *command);
void	check_error(void);

#endif /* EXIT_SHELL_H */
