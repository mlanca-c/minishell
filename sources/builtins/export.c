/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/01/31 11:08:34 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_sorted_env(t_list *env)
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

int	export_builtin(t_cmd *cmd)
{
	t_ctrl	*controllers;
	t_list	*sorted_env;
	
	controllers = init_controllers(NULL);
	if (!cmd->suffix)
	{
		sorted_env = controllers->envp;
		while (sorted(sorted_env) != 0)
			sort_env(sorted_env);
		print_sorted_env(sorted_env);
	}
	else
	{
		ft_lst_add_back(&controllers->envp, cmd->suffix);
		print_sorted_env(controllers->envp);
	}
	return (SUCCESS);
}
