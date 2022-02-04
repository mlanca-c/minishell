/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:21:55 by josantos          #+#    #+#             */
/*   Updated: 2022/02/03 17:28:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(void)
{
	t_list	*lst;

	lst = init_controllers(NULL)->envp;
	while (lst)
	{
		if (ft_strchr(lst->content, '='))
			printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (SUCCESS);
}
