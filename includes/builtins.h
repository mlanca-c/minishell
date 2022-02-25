/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2022/02/22 13:52:59 by mlanca-c         ###   ########.fr       */
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

typedef struct s_export_vars
{
	char	*var_name;
	char	*var_val;
}	t_exp_vars;

void		temporary_builtin_redirection(t_list *lst);
int			cd_builtin(t_cmd *cmd);
int			echo_builtin(t_cmd *cmd);
int			pwd_builtin(t_cmd *cmd);
int			export_builtin(t_cmd *cmd);
int			env_builtin(t_cmd *cmd);

/* export utils */
void		print_export_env(t_exp_vars *vars);
t_exp_vars	*init_exp_vars(t_cmd *cmd);
void		free_export_vars(t_exp_vars *vars);

#endif /* BUILTINS_H */
