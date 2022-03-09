/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:23:01 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 20:26:56 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("Error with pipe/n");
		return (FAILURE);
	}
	return (SUCCESS);
}