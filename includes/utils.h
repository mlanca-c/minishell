/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 18:46:25 by mlanca-c         ###   ########.fr       */
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
void	free_token(t_list *token_list);

// DEBUGGING FUNCTIONS - TO DELETE
void	print_token(t_list *token_list);
void	print_controllers(t_ctrl *controllers);
void	print_commands(t_cmd *command);

#endif /* UTILS_H */
