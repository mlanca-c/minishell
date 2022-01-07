/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/01/07 12:17:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**sort_env(t_list **envp)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 1;
	while (envp)
	{
		while (envp[i] && envp[j])
		{
			if (ft_strncmp(envp[i]->content, envp[j]->content, 1000) > 0)
			{
				temp = envp[i]->content;
				envp[i]->content = envp[j]->content;
				envp[j]->content = temp;
			}
			else
				break;
		}
		i++;
		j++;
	}
	return (envp);
}

int	export_builtin(t_ctrl *controllers)
{
	int		i;
	char	*suffix;
	t_list	**sorted_env;
	
	i = -1;
	suffix = NULL;
	if (!suffix)
	{
		sorted_env = sort_env(controllers->envp);
		while (sorted_env[i])
			printf("%s\n", sorted_env[i]->content);
	}
	return (SUCCESS);
}
