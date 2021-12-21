/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2021/12/21 18:32:10 by josantos         ###   ########.fr       */
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

typedef struct	s_env_var
{
	char	**process_paths;
	char	*curr_wd;
	char 	*prev_wd;
	char	*home_dir;
	int		exit_status;
	char	**envp;
}	t_env_var;

int	cd_builtin(t_env_var *var);
int	echo_builtin(void);
int	pwd_builtin(void);
int	export_builtin(t_env_var *var, char **envp);
int	env_builtin(char **envp);

#endif /* BUILTINS_H */
