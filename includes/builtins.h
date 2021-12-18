/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2021/12/18 18:24:49 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct	s_env_var
{
	char	**process_paths;
	char	*curr_wd;
	char 	*prev_wd;
	char	*home_dir;
}	t_env_var;

void	cd_builtin(t_env_var *var);
void	echo_builtin(void);
void	pwd_builtin(void);
void	export_builtin(t_env_var *var, char **envp);
void	env_builtin(char **envp);

#endif /* BUILTINS_H */
