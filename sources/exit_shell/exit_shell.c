/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/01 12:53:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function focuses in freeing everything and exiting the program. */
void	exit_shell(void)
{
	t_ctrl	*controllers;
	int		error;

	controllers = scan_controllers(NULL);
	if (!controllers)
		exit(EXIT_FAILURE);
	error = controllers->return_value;
	free_controllers(controllers);
	if (error)
		exit(error);
	exit(EXIT_SUCCESS);
}
