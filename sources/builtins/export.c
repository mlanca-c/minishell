/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/03/04 18:14:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_sorted_env(t_dict *envp);
static void	export_without_value(t_dict *envp, char *variable);
static void	export_with_value(t_dict *envp, char *variable);

int	export_builtin(t_cmd *command)
{
	t_dict	*envp;
	t_list	*lst;

	envp = scan_controllers(NULL)->envp;
	if (!envp)
		return (BUILTIN_FAILURE);
	if (!command->suffix)
	{
		print_sorted_env(envp);
		return (SUCCESS);
	}
	lst = command->suffix;
	while (lst)
	{
		if (ft_strfind(lst->content, "=") == -1)
			export_without_value(envp, lst->content);
		else
			export_with_value(envp, lst->content);
		lst = lst->next;
	}
	return (SUCCESS);
}

static void	print_sorted_env(t_dict *envp)
{
	t_dict	*sorted;

	sorted = ft_dict_copy(envp);
	ft_dict_sort(&sorted);
	ft_dict_print(sorted, "declare -x %s\"%s\"\n", "declare -x %s\n");
	ft_dict_clear(sorted, free);
}

static void	export_without_value(t_dict *envp, char *variable)
{
	char	*key;

	key = ft_strjoin(variable, "=");
	if (ft_dict_key_exists(envp, key) || ft_dict_key_exists(envp, variable))
	{
		free(key);
		return ;
	}
	ft_dict_add_back(&envp, ft_dict_new(variable, NULL));
	free(key);
}

static void	export_with_value(t_dict *envp, char *variable)
{
	char	*key;
	char	*value;

	key = ft_substr(variable, 0, ft_strfind(variable, "=") + 1);
	value = ft_substr(variable, ft_strfind(variable, "=") + 1,
		ft_strlen(variable));
	if (!scan_envp(key, NULL))
		ft_dict_add_back(&envp, ft_dict_new(key, value));
	else
	{
		scan_envp(key, value);
		free(key);
	}
}

// int	export_builtin(t_cmd *command)
// {
// 	t_dict	*envp;
// 	t_dict	*sorted;
// 	t_list	*lst;
// 	char	*key;
// 	char	*value;

// 	envp = scan_controllers(NULL)->envp;
// 	if (!command->suffix)
// 	{
// 		sorted = ft_dict_copy(envp);
// 		ft_dict_sort(&sorted);
// 		ft_dict_print(sorted, "declare -x %s\"%s\"\n", "declare -x %s\n");
// 		ft_dict_clear(sorted, free);
// 	}
// 	else
// 	{
// 		lst = command->suffix;
// 		while (lst)
// 		{
// 			value = NULL;
// 			if (ft_strfind(lst->content, "=") == -1)
// 			{
// 				key = lst->content;
// 				if (key_exists(key))
// 				{
// 					lst = lst->next;
// 					continue ;
// 				}
// 			}
// 			else
// 			{
// 				key = ft_substr(lst->content, 0,
// 					ft_strfind(lst->content, "=") + 1);
// 				value = ft_substr(lst->content,
// 					ft_strfind(lst->content, "=") + 1, ft_strlen(lst->content));
// 				if (scan_envp(key, NULL))
// 					ft_dict_replace(envp, key, value);
// 				else
// 					ft_dict_add_back(&envp, ft_dict_new(key, value));
// 				printf("new key: %s\nnew value: %s\n", key, value);
// 			}
// 			// ft_dict_add_back(&envp, ft_dict_new(key, value));
// 			free(value);
// 			lst = lst->next;
// 		}
// 	}
// 	return (SUCCESS);
// }

// static int	key_exists(char *key)
// {
// 	char	*temporary;

// 	temporary = ft_strjoin(key, "=");
// 	if (!scan_envp(temporary, NULL) && !scan_envp(key, NULL))
// 	{
// 		printf("This key does not exist.\n");
// 		free(temporary);
// 		return (0);
// 	}
// 	printf("This key already exists and might have a value.\n");
// 	free(temporary);
// 	return (1);
// }
