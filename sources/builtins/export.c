/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2021/12/18 18:35:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_builtin(t_env_var *var, char **envp)
{
	static char **env_var;
	char 		*line_add = "banana=amarela";
	int			i;
	(void)var;
	
	i = 0;
	env_var = envp;
	while (env_var[i])
		i++;
	envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!envp)
		perror("malloc error - export");
	i = 0;
	while (env_var[i])
	{
		envp[i] = env_var[i];
		i++;
	}
	envp[i] = line_add;
}
