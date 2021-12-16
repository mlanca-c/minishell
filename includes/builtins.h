/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2021/12/16 16:42:04 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	cd_builtin(void);
void	echo_builtin(void);
void	pwd_builtin(void);

typedef struct	s_env_var
{
	char	*curr_wd;
	char	*cd_arg;
	char	*home_dir;
}	t_env_var;

#endif /* BUILTINS_H */
