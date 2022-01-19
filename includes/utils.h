/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 13:14:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* constrollers.c Functions */
t_ctrl	*init_controllers(char *envp[]);
char	**get_controllers_path(char *envp[]);
char	*get_controllers_home(char *envp[]);
void	free_controllers(t_ctrl *controllers);

/* exit_shell.c Functions */
void	exit_shell(void);

// DEBUGGING FUNCTIONS - TO DELETE
void	print_controllers(void);
void	print_token(t_token *token);
void	print_parser(t_ast *parser);
void	print_command(t_cmd *command, int level);

#endif /* UTILS_H */
