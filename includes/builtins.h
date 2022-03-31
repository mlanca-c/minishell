/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2022/03/31 17:20:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/* builtins */
int			cd_builtin(t_cmd *command);
int			echo_builtin(t_cmd *command);
int			env_builtin(t_cmd *command);
int			exit_builtin(t_cmd *command);
int			export_builtin(t_cmd *command);
int			pwd_builtin(t_cmd *command);
int			unset_builtin(t_cmd *command);

/* execution */
int			is_builtin(t_cmd *command);
int			exec_builtin(t_cmd *command);

#endif /* BUILTINS_H */
