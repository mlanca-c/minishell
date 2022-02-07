/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 00:38:30 by josantos         ###   ########.fr       */
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
	t_ht	*ht;
}	t_exp_vars;

int			cd_builtin(t_cmd *cmd);
int			echo_builtin(t_cmd *cmd);
int			pwd_builtin(void);
int			export_builtin(t_cmd *cmd);
int			env_builtin(void);
	
/* export utils */
	
int			sorted(t_ht *ht);
void		sort_env(t_ht *ht);
void		print_export_env(t_exp_vars *vars);
t_exp_vars	*init_exp_vars(t_cmd *cmd);
t_ht		*init_hashtable(void);
void		free_export_vars(t_exp_vars *vars);

#endif /* BUILTINS_H */
