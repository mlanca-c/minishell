/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:15:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/01 12:02:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/* execution.c Functions */
void	resrap(void);

/* utils Functions */
t_list	*t_red_copy(t_list *origin, int end);

/* execution.c Functions */
t_list	*scan_command(t_cmd *command);
t_node	*scan_node(t_ast *parser_tree);

/* Processes Functions */

void	exec_child(t_cmd *cmd);
void	exec_parent(void);
char	**lst_tostr(t_list *envp);
char	**get_array(t_cmd *cmd);

/* Processes_utils Functions */
int		has_path(t_cmd *cmd);
char	*get_path(t_cmd *cmd);
char	*check_stat(char **path, t_cmd *cmd);

#endif /* EXECUTION_H */
