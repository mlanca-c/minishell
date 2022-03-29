/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2022/03/29 21:02:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	find_flag(char *arg);

int	echo_builtin(t_cmd *command)
{
	bool	flag;

	if (!command->suffix)
		printf("\n");
	else
	{
		flag = find_flag(command->suffix->content);
		if (flag == false)
		{
			ft_dlst_print(command->suffix, " ");
			printf("\n");
		}
		else
		{
			ft_dlst_print(command->suffix->next, " ");
		}
	}
	return (SUCCESS);
}

static bool	find_flag(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] == '-')
	{
		while (arg[i])
			if (arg[i++] != 'n')
				return (false);
		return (true);
	}
	return (false);
}
