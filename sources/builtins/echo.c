/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2021/12/16 13:13:54 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(void)
{
	char	*str = "aaa";
	char	*suffix = "-nnnnn -nnnnn";
	size_t	i;
	bool	valid = true;

	i = 0;
	if (suffix)
	{
		while (++i < ft_strlen(suffix))
			if (ft_strncmp(&suffix[i], "n", 1))
				valid = false;
		if (valid == false)
		{
			printf("%s ", suffix);
			printf("%s\n", str);
			return ;
		}
		else
		{
			printf("%s", str);
			return ;
		}
	}
	printf("%s", str);
	printf("\n");
}
