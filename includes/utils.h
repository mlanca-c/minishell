/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:19:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Error Status Macros */
# define E_MALLOC_CTRL	0
# define E_NULL			1

/* constrollers.c Functions */
t_ctrl	*init_controllers(char *envp[]);
char	**get_controllers_path(char *envp[]);
char	*get_controllers_home(char *envp[]);

/* exit_shell.c Functions */
void	exit_shell(int status);
void	token_free(t_list *token_list);

// DEBUGGING FUNCTIONS - TO DELETE
void	print_token(t_list *token_list);
void	print_controllers(t_ctrl *controllers);
void	print_simple_commands(t_simple_command *simple_commands);

#endif /* UTILS_H */
