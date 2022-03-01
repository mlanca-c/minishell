/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:21:55 by josantos          #+#    #+#             */
/*   Updated: 2022/03/01 20:44:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_cmd *command)
{
	(void)command;
	ft_dict_print(scan_controllers(NULL)->envp, "%s%s\n");
	return (SUCCESS);
}
