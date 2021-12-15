/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2021/12/15 16:34:52 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(void)
{
	char	*str = "";
	char	*suffix = "-nnnnnnn";

	if (str)
		printf("%s", str);
	if (suffix && !ft_strncmp(suffix, "-n", 2))
		return ;
	else
		printf("\n");
}
