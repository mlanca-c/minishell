/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 21:26:54 by mlanca-c         ###   ########.fr       */
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

#endif /* EXIT_SHELL_H */
