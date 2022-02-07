/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:40 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 00:43:21 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_env(t_exp_vars *vars)
{
	while (vars->ht)
	{
		printf("declare -x ");
		printf("%s=", (char *)vars->ht->env_name);
		printf("\"%s\"\n", vars->ht->env_val);
		vars->ht = vars->ht->next;
	}
}

void	sort_env(t_ht *ht)
{
	char	*temp;
	char	*temp2;

	while (ht && ht->next)
	{
		if (strncmp(ht->env_name, ht->next->env_name,
				ft_strlen(ht->env_name) + ft_strlen(ht->next->env_name)) > 0)
		{
			temp = ht->env_name;
			temp2 = ht->env_val;
			ht->env_name = ht->next->env_name;
			ht->env_name = ht->next->env_name;
			ht->next->env_name = temp;
			ht->next->env_val = temp2;
		}
		ht = ht->next;
	}
}

int	sorted(t_ht *ht)
{
	int	checker;

	checker = 0;
	while (ht && ht->next)
	{
		if (strncmp(ht->env_name, ht->next->env_name,
				ft_strlen(ht->env_name) + ft_strlen(ht->next->env_name)) > 0)
		{
			checker++;
		}
		ht = ht->next;
		if (checker != 0)
			break ;
	}
	return (checker);
}

t_ht	*init_hashtable(void)
{
	t_ht	*ht;
	t_ctrl	*controllers;
	
	controllers = init_controllers(NULL);
	/*ht = (t_ht *)ft_calloc(1, sizeof(t_ht));
	if (!ht)
		exit_shell();*/
	while (controllers->envp)
	{
		printf("%s\n", (char *)controllers->envp->content);
		ht_add_back(&ht, ht_new(controllers->envp->content));
		printf("name:%s\tvalue:%s\n", ht->env_name, ht->env_val);
		controllers->envp = controllers->envp->next;
	}
	return (ht);
}

void	free_export_vars(t_exp_vars *vars)
{
	ht_clear(vars->ht, free);
	free(vars->var_val);
	free(vars->var_name);
}

t_exp_vars	*init_exp_vars(t_cmd *cmd)
{
	t_exp_vars	*vars;
	t_ctrl		*controllers;
	//int			i;

	controllers = init_controllers(NULL);
	vars = (t_exp_vars *)ft_calloc(1, sizeof(t_exp_vars));
	if (!vars)
		exit_shell();
	//vars->env_lst = ft_lst_copy(controllers->envp, ft_lst_size(controllers->envp));
	vars->ht = init_hashtable();
	while (controllers->envp)
	{
		printf("name:%s\tvalue:%s\n", vars->ht->env_name, vars->ht->env_val);
		controllers->envp = controllers->envp->next;
	}
	cmd->prefix = NULL;
	/*
	if (cmd->suffix)
	{
		if (ft_strchr(cmd->suffix->content, '='))
		{
			i = ft_strfind(cmd->suffix->content, "=");
			vars->var_name = ft_substr(cmd->suffix->content, 0, i);
			vars->var_val = ft_substr(cmd->suffix->content, i, ft_strlen(cmd->suffix->content));
		}
		else
			vars->var_name = ft_substr(cmd->suffix->content, 0, ft_strlen(cmd->suffix->content));
	}*/
	return (vars);
}
