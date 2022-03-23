/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/03/23 10:55:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid(char *str);
static void	print_sorted_env(t_dict *envp);
static void	export_with_value(t_dict *envp, char *variable);

//validate variable and value.
int	export_builtin(t_cmd *command)
{
	t_dict	*envp;
	t_list	*lst;

	envp = scan_controllers(NULL)->envp;
	if (!command->suffix)
	{
		print_sorted_env(envp);
		return (SUCCESS);
	}
	lst = command->suffix;
	while (lst)
	{
		if (!is_valid(lst->content))
			return (FAILURE);
		if (ft_strfind(lst->content, "=") == -1)
		{
			if (!ft_dict_key_exists(envp, lst->content))
				ft_dict_add_back(&envp, ft_dict_new(ft_strdup(lst->content),
						NULL));
		}
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
	ft_dict_print(sorted, "declare -x %s=\"%s\"\n", "declare -x %s\n");
	ft_dict_clear(sorted, free);
}

static void	export_with_value(t_dict *envp, char *variable)
{
	char	*key;
	char	*value;

	key = ft_substr(variable, 0, ft_strfind(variable, "="));
	if (variable[ft_strlen(variable) - 1] == '=')
		value = ft_strdup("");
	else
		value = ft_substr(variable, ft_strfind(variable, "=") + 1,
				ft_strlen(variable));
	if (!ft_dict_key_exists(envp, key))
		ft_dict_add_back(&envp, ft_dict_new(key, value));
	else
	{
		scan_envp(key, value);
		free(key);
	}
}

static int	is_valid(char *str)
{
	if (ft_isdigit(str[0]) || ft_strchr(str, '@'))
	{
		printf("%s: export: \'%s\' not a valid identifier\n", SHELL, str);
		return (0);
	}
	return (1);
}
