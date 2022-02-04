/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/02/04 10:59:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_export_suffix(t_cmd *cmd)
{
	char	*var;
	t_ctrl	*controllers;
	t_list	*lst;
	int		i;
	char	*env_name;
	char	*env_val;
	bool	found;

	controllers = init_controllers(NULL);
	lst = ft_lst_copy(controllers->envp, ft_lst_size(controllers->envp));
	var = ft_strdup(cmd->suffix->content);
	found = false;
	if (!ft_strchr(var, '='))
	{
		while (lst)
		{
			i = ft_strfind(lst->content, "=");
			env_name = ft_substr(lst->content, 0, i - 1);
			if (!ft_strncmp(var, env_name, ft_strlen(env_name) + ft_strlen(var)))
			{
				found = true;
				break;
			}
			else
				lst = lst->next;
		}
		if (found == false)
			ft_lst_add_back(&controllers->envp, ft_lst_new(var));
	}
	else
		while (lst)
		{
			i = ft_strfind(lst->content, "=");
			env_name = ft_substr(lst->content, 0, i - 1);
			env_val = ft_substr(lst->content, i + 1, ft_strlen(lst->content));
			if (!ft_strncmp(var, env_name, ft_strlen(env_name) + ft_strlen(var)))
			{
				ft_str_replace(lst->content, env_val, var + i + 1);
				found = true;
				break ;
			}
			else
				lst = lst->next;
			if (found == false)
				ft_lst_add_back(&controllers->envp, ft_lst_new(var));
		}
}

int	export_builtin(t_cmd *cmd)
{
	t_ctrl	*controllers;
	t_list	*sorted_env;

	controllers = init_controllers(NULL);
	if (!cmd->suffix)
	{
		sorted_env = ft_lst_copy(controllers->envp, ft_lst_size(controllers->envp));
		while (sorted(sorted_env) != 0)
			sort_env(sorted_env);
		print_export_env(sorted_env);
		ft_lst_clear(sorted_env, free);
	}
	else
		do_export_suffix(cmd);
	
	return (SUCCESS);
}
