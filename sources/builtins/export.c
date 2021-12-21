/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2021/12/21 19:08:16 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_node(t_list **list, char *data)
{
	t_list *temp;
	
	if (!list)
		*list = ft_list_new(data);
	else
	{
		temp = ft_list_new(data);
		ft_lst_add_back(list, temp);
	}
}

void	**sort_lst(t_list **list)
{

}

int	export_builtin(t_env_var *var)
{
	int		i;
	t_list	**env_list;
	char *suffix;
	
	i = -1;
	if (!suffix)
	{
		env_list = var->envp;
		sort_lst(env_list);
		while (env_list[++i])
			printf("%s\n", env_list[i]);
		return (SUCCESS);
	}
	while(var->envp[i])
	{
		create_node(env_list, var->envp[i]);
		i++;
	}
	if (!token)
		print_export_vars(env_list);
}
