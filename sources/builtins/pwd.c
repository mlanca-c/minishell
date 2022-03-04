/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:47:24 by josantos          #+#    #+#             */
/*   Updated: 2022/03/01 19:50:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This is the builtin command pwd - outputs the current absolute path */
int	pwd_builtin(t_cmd *command)
{
	(void)command;
	printf("%s\n", scan_envp("PWD=", NULL));
	return (SUCCESS);
}
