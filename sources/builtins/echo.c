/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2021/12/21 18:41:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(void)
{
	char	*str = "aaa";
	char	*flag = "-nnnnn -nnnnn";
	size_t	i;
	bool	valid = true;

	i = 0;
	if (flag)
	{
		while (++i < ft_strlen(flag))
			if (ft_strncmp(&flag[i], "n", 1))
				valid = false;
		if (valid == false)
			printf("%s %s\n", flag, str);
		else
			printf("%s", str);
	}
	else
		printf("%s\n", str);
	return (SUCCESS);
}
