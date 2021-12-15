/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2021/12/15 11:59:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(void)
{
	char	*pwd;
	int		i;

	i = 0;
	pwd = NULL;
	pwd = getcwd(NULL, 0);
	chdir("..");
	free(pwd);
	pwd = getcwd(NULL, 0);
	free(pwd);
}
