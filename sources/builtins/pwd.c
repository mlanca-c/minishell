/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:47:24 by josantos          #+#    #+#             */
/*   Updated: 2022/03/23 11:06:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This is the builtin command pwd - outputs the current absolute path */
int	pwd_builtin(t_cmd *command)
{
	char	*str;

	(void)command;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (SUCCESS);
}
