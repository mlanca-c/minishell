/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2021/12/18 18:23:10 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(t_env_var *var)
{
	char *cd_arg = "-";
	static int	i = 0;
	//var->cd_arg -> args for cd to work, will be what is parsed in the future;

	if (!ft_strncmp(cd_arg, "-", 1))
		chdir(var->prev_wd);
	else if (!ft_strncmp(cd_arg, "", 1))
		chdir(var->home_dir);
	else
		chdir(cd_arg);
	var->prev_wd = var->curr_wd;
	var->curr_wd = getcwd(NULL, 0);
	i++;
}
