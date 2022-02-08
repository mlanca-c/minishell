/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:15:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 11:23:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/* execution.c Functions */
void	execution(void);
void	execute_list(t_ast *parser_tree);
void	execute_pipeline(t_ast *parser_tree);
void	execute_command(t_ast *parser_tree);
t_node	*scan_node(t_ast *parser_tree);

/*method.c Functions */
void	execute_method(t_cmd *cmd);
void	do_builtins(t_cmd *cmd);

#endif /* EXECUTION_H */
