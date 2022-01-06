/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/01/06 11:21:38 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dir(char *cd_arg)
{
	DIR	*checker;

	checker = opendir(cd_arg);
	if (!checker)
		return (BUILTIN_FAILURE);
	else
		return (0);
}

int	cd_builtin(t_env_var *var)
{
	char *cd_arg = "-";
	static int	i = 0;

	if (check_dir(cd_arg))
		return (BUILTIN_FAILURE);
	else
	{
		if (!ft_strncmp(cd_arg, "-", 1))
			chdir(var->prev_wd);
		else if (!ft_strncmp(cd_arg, "", 1) || !ft_strncmp(cd_arg, "~", 1)
			|| !ft_strncmp(cd_arg, "--", 2))
			chdir(var->home_dir);
		else
			chdir(cd_arg);
		var->prev_wd = var->curr_wd;
		var->curr_wd = getcwd(NULL, 0);
		i++;
	}
	return (SUCCESS);
}
