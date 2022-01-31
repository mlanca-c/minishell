/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:21:55 by josantos          #+#    #+#             */
/*   Updated: 2022/01/31 16:19:16 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(void)
{
	t_ctrl	*controllers;
	t_list	*lst;
	
	controllers = init_controllers(NULL);
	lst = controllers->envp;
	while (lst)
	{
		if (ft_strchr(lst->content, '='))
			printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (SUCCESS);
}