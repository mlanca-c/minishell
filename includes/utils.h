/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 13:44:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* constrollers.c Functions */
t_dict	*controllers_get_envp(char *envp[]);

/* scanners.c Functions */
t_ctrl	*scan_controllers(char *envp[]);
t_err_t	scan_error(void *err);
char	*scan_envp(char *key, char *value);
char	**scan_path(void);

/* exit_shell.c Functions */
void	exit_shell(void);
void	free_controllers(t_ctrl *controllers);
void	free_node(void *ast_node);

/* debugger Functions */
void	print_controllers(void);
void	print_tokens(void);
void	print_parser(void);
void	print_command(t_cmd *command);
void	print_commands(t_ast *parser);
void	print_command_lst(t_list *lst);

#endif /* UTILS_H */
