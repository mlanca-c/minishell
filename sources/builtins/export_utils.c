/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:40 by josantos          #+#    #+#             */
/*   Updated: 2022/02/05 19:19:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_env(t_list *env)
{
	while (env)
	{
		printf("declare -x ");
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
}

void	sort_env(t_list *lst)
{
	char	*temp;

	while (lst && lst->next)
	{
		if (strncmp(lst->content, lst->next->content,
				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
		{
			temp = lst->content;
			lst->content = lst->next->content;
			lst->next->content = temp;
		}
		lst = lst->next;
	}
}

int	sorted(t_list *lst)
{
	int	checker;

	checker = 0;
	while (lst && lst->next)
	{
		if (strncmp(lst->content, lst->next->content,
				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
		{
			checker++;
		}
		lst = lst->next;
		if (checker != 0)
			break ;
	}
	return (checker);
}

t_exp_vars	*init_exp_vars(t_cmd *cmd, t_ctrl *controllers)
{
	t_exp_vars	*vars;
	int			i;

	vars = (t_exp_vars *)ft_calloc(1, sizeof(t_exp_vars));
	if (!vars)
		exit_shell();
	vars->env_lst = ft_lst_copy(controllers->envp, ft_lst_size(controllers->envp));
	vars->var = ft_strdup(cmd->suffix->content);	
	while (vars->env_lst)
	{
		i = ft_strfind(vars->env_lst->content, "=");
		vars->env_name = ft_substr(vars->env_lst->content, 0, i - 1);
		vars->env_val = ft_substr(vars->env_lst->content, i + 1, ft_strlen(vars->env_lst->content));
		if (!cmd->suffix)
			break ;
		else
		{
			i = ft_strfind(vars->var, "=");
			vars->var_val = ft_substr(vars->var, 0, i);
			vars->env_lst = vars->env_lst->next;
		}
	}
	return (vars);
}

void	free_export_vars(t_exp_vars *vars)
{
	free(vars->env_name);
	free(vars->env_val);
	free(vars->var);
	free(vars->var_val);
	ft_lst_clear(vars->env_lst, free);
}