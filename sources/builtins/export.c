/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/02/04 18:03:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_only_name(t_list *lst, t_exp_vars *vars, t_ctrl *controllers)
{
	bool	found;
	
	found = false;
	while (lst)
	{
		if (!ft_strncmp(vars->var, vars->env_name, ft_strlen(vars->env_name) + ft_strlen(vars->var)))
		{
			found = true;
			break;
		}
		else
			lst = lst->next;
	}
	if (found == false)
		ft_lst_add_back(&controllers->envp, (ft_lst_new(ft_strdup(vars->var))));
}

void	do_name_val(t_list *lst, t_exp_vars *vars, t_ctrl *controllers)
{
	bool	found;
	
	found = false;
	while (lst)
	{
		//printf("var:%s, env_name:%s, env_val:%s\n", vars->var_val, vars->env_name, vars->env_val);
		if (!ft_strncmp(vars->var_val, vars->env_name, ft_strlen(vars->var_val)))
		{
			ft_str_replace(lst->content, vars->env_val, vars->var_val);
			found = true;
			break ;
		}
		else
			lst = lst->next;
	}
	if (found == false)
		ft_lst_add_back(&controllers->envp, ft_lst_new(ft_strdup(vars->var)));
}

void	do_export_suffix(t_exp_vars *vars)
{
	t_ctrl		*controllers;

	controllers = init_controllers(NULL);
	if (!ft_strchr(vars->var, '='))
		do_only_name(vars->env_lst, vars, controllers);
	else
		do_name_val(vars->env_lst, vars, controllers);
}

int	export_builtin(t_cmd *cmd)
{
	t_ctrl	*controllers;
	t_list	*sorted_env;
	t_exp_vars	*vars;

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
	{
		vars = init_exp_vars(cmd, controllers);
		do_export_suffix(vars);
		free_export_vars(vars);
	}
	return (SUCCESS);
}
