/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:05 by josantos          #+#    #+#             */
/*   Updated: 2022/03/01 19:44:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_sorted_env(t_list *env)
// {
// 	while (env)
// 	{
// 		printf("declare -x ");
// 		printf("%s\n", (char *)env->content);
// 		env = env->next;
// 	}
// }

// void	sort_env(t_list *lst)
// {
// 	char	*temp;

// 	while (lst && lst->next)
// 	{
// 		if (strncmp(lst->content, lst->next->content,
// 				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
// 		{
// 			temp = lst->content;
// 			lst->content = lst->next->content;
// 			lst->next->content = temp;
// 		}
// 		lst = lst->next;
// 	}
// }

// int	sorted(t_list *lst)
// {
// 	int	checker;

// 	checker = 0;
// 	while (lst && lst->next)
// 	{
// 		if (strncmp(lst->content, lst->next->content,
// 				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
// 		{
// 			checker++;
// 		}
// 		lst = lst->next;
// 		if (checker != 0)
// 			break ;
// 	}
// 	return (checker);
// }

// void	do_export_suffix(t_cmd *cmd)
// {
// 	char	*var;
// 	t_ctrl	*controllers;
// 	char	*var_name;

// 	controllers = scan_controllers(NULL);
// 	var = ft_strdup(cmd->suffix->content);
// 	var_name = ft_strdup("");
// 	if (!ft_strncmp(var, var_name, ft_strlen(var_name)))
// 		ft_lst_add_back(&controllers->envp, ft_lst_new(var));
// 	print_sorted_env(controllers->envp);
// }

// int	export_builtin(t_cmd *cmd)
// {
// 	t_ctrl	*controllers;
// 	t_list	*sorted_env;

// 	controllers = scan_controllers(NULL);
// 	if (!cmd->suffix)
// 	{
// 		sorted_env = controllers->envp;
// 		while (sorted(sorted_env) != 0)
// 			sort_env(sorted_env);
// 		print_sorted_env(sorted_env);
// 	}
// 	else
// 		do_export_suffix(cmd);
// 	return (SUCCESS);
// }
