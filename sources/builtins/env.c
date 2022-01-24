/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:21:55 by josantos          #+#    #+#             */
/*   Updated: 2022/01/07 10:52:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_ctrl *controllers)
{
	int i;
	
	i = -1;
	while (controllers->envp[++i])
		printf("%s\n", controllers->envp[i]->content);
	return (SUCCESS);
}