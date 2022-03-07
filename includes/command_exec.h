/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:23:50 by josantos          #+#    #+#             */
/*   Updated: 2022/03/07 12:47:10 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXEC_H
# define COMMAND_EXEC_H

/* command_execution Functions */
int		is_builtin(t_cmd *cmd);
void	exec_builtin(t_cmd *cmd);
void	exec_program(t_cmd *cmd);
void	close_pipes(t_cmd_info *info, int type);
void	exec_child(t_cmd *cmd);


#endif