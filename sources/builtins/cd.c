/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2021/12/16 16:45:15 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(void)
{
	t_env_var	*var;
	static int	i = 0;
	static char	*prev_wd;

	var = (t_env_var *)malloc(sizeof(t_env_var *));
	if (!var)
		perror("t_env_var malloc error");
	var->home_dir = getenv("HOME"); //To delete
	var->curr_wd = getcwd(NULL, 0);
	if (!ft_strncmp(var->cd_arg, "-", 1))
		chdir(prev_wd);
	else if (!ft_strncmp(var->cd_arg, "", 1))
		chdir(var->home_dir);
	else
		chdir(var->cd_arg);
	prev_wd = var->curr_wd;
	var->curr_wd = getcwd(NULL, 0);
	i++;
}
