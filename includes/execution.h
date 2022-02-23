/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:15:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/23 19:24:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/* execution.c Functions */
void	resrap(void);
void	execute(t_list *command);
void	execute_list(t_ast *parser_tree);
void	execute_pipeline(t_ast *parser_tree);
void	execute_command(t_ast *parser_tree);

/* execution.c Functions */
t_list	*scan_command(t_cmd *command);
t_node	*scan_node(t_ast *parser_tree);

#endif /* EXECUTION_H */
