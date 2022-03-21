/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/17 16:46:39 by josantos         ###   ########.fr       */
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

/* error messages Functions */

void	process_err(char *argv, char *message);
void	open_err(char *file, char *message);
void	path_err(char *argv, char *message);

#endif /* EXIT_SHELL_H */
