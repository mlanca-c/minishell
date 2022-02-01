/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2022/02/01 14:42:55 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define SUCCESS 			0
# define GENERAL_FAILURE	1
# define BUILTIN_FAILURE	2
# define COMMAND_FAILURE	126
# define COMMAND_NOT_FOUND	127
# define CONTROL_C 			130

int		cd_builtin(t_cmd *cmd);
int		echo_builtin(t_cmd *cmd);
int		pwd_builtin(void);
int		export_builtin(t_cmd *cmd);
int		env_builtin(void);

/* export_utils */

int		sorted(t_list *lst);
void	sort_env(t_list *lst);
void	print_export_env(t_list *env);

#endif /* BUILTINS_H */
