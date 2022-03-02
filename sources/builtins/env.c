/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:21:55 by josantos          #+#    #+#             */
/*   Updated: 2022/03/02 12:22:43 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_cmd *command)
{
	(void)command;
	ft_dict_print(scan_controllers(NULL)->envp, "%s%s\n");
	return (SUCCESS);
}
