/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 17:18:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* constrollers.c Functions */
t_ctrl	*init_controllers(char *envp[]);
char	**get_controllers_path(char *envp[]);
char	*get_controllers_home(char *envp[]);

/* exit_shell.c Functions */
void	exit_shell(void);
void	free_token(void *token);
void	free_command(t_cmd *command);

// DEBUGGING FUNCTIONS - TO DELETE
void	print_controllers(t_ctrl *controllers);
void	print_token(t_list *token_list);
void	print_command(t_cmd *command);

#endif /* UTILS_H */
