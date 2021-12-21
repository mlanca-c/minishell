/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:47:24 by josantos          #+#    #+#             */
/*   Updated: 2021/12/21 18:42:23 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_builtin(void)
{
	char	*pwd;
	char	*suffix;

	pwd = NULL;
	if (suffix)
	{
		printf("pwd: too many arguments");
		return (BUILTIN_FAILURE);
	}
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (SUCCESS);
}
