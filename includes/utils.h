/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/26 12:37:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* constrollers.c Functions */
t_ctrl	*init_controllers(char *envp[]);
char	*get_controllers_dir(char *envp[]);
char	**get_controllers_path(char *envp[]);
char	*get_controllers_home(char *envp[]);
t_list	*get_controllers_envp(char *envp[]);

/* exit_shell.c Functions */
void	exit_shell(void);
void	free_controllers(t_ctrl *controllers);
void	free_node(void *ast_node);
t_err_t	find_error(void);

/* debugger Functions */
void	print_controllers(void);
void	print_tokens(void);
void	print_parser(void);
void	print_command(t_cmd *command);
void	print_commands(t_ast *parser);
void	print_command_lst(t_list *lst);

#endif /* UTILS_H */
