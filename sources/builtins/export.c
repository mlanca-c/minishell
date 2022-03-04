/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/03/03 16:56:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	key_exists(char *key);

int	export_builtin(t_cmd *command)
{
	t_dict	*envp;
	t_dict	*sorted;
	t_list	*lst;
	char	*key;
	char	*value;

	envp = scan_controllers(NULL)->envp;
	if (!command->suffix)
	{
		sorted = ft_dict_copy(envp);
		ft_dict_sort(&sorted);
		ft_dict_print(sorted, "declare -x %s\"%s\"\n", "declare -x %s\n");
		ft_dict_clear(sorted, free);
	}
	else
	{
		lst = command->suffix;
		while (lst)
		{
			value = NULL;
			if (ft_strfind(lst->content, "=") == -1)
			{
				key = lst->content;
				if (key_exists(key))
				{
					lst = lst->next;
					continue ;
				}
			}
			else
			{
				key = ft_substr(lst->content, 0,
					ft_strfind(lst->content, "=") + 1);
				value = ft_substr(lst->content,
					ft_strfind(lst->content, "=") + 1, ft_strlen(lst->content));
				if (scan_envp(key, NULL))
					ft_dict_replace(envp, key, value);
				else
					ft_dict_add_back(&envp, ft_dict_new(key, value));
				printf("new key: %s\nnew value: %s\n", key, value);
			}
			ft_dict_add_back(&envp, ft_dict_new(key, value));
			lst = lst->next;
		}
	}
	return (SUCCESS);
}

static int	key_exists(char *key)
{
	char	*temporary;

	temporary = ft_strjoin(key, "=");
	if (!scan_envp(temporary, NULL) && !scan_envp(key, NULL))
	{
		printf("This key does not exist.\n");
		free(temporary);
		return (0);
	}
	printf("This key already exists and might have a value.\n");
	free(temporary);
	return (1);
}
