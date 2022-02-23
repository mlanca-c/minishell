/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:45:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/23 19:13:04 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	*controllers_get_envp(char *envp[])
{
	int		i;
	t_dict	*dict;
	char	*key;
	char	*value;

	dict = NULL;
	i = 0;
	while (envp[i])
	{
		key = ft_substr(envp[i], 0, ft_strfind(envp[i], "=") + 1);
		value = ft_substr(envp[i], ft_strfind(envp[i], "=") + 1,
				ft_strlen(envp[i]));
		ft_dict_add_back(&dict, ft_dict_new(key, value));
		i++;
	}
	return (dict);
}

t_list	*get_controllers_env(char *envp[])
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	while (envp[i])
		ft_lst_add_back(&list, ft_lst_new(ft_strdup(envp[i++])));
	return (list);
}
