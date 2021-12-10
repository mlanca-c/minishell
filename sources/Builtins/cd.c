/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:24:44 by josantos          #+#    #+#             */
/*   Updated: 2021/12/10 11:42:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(char **argv)
{
	char *current_path;
	char *go2path;

	go2path = malloc(sizeof())
	current_path = getcwd(current_path, sizeof(current_path));
	chdir();
}