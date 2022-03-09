/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_std_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:59:43 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 21:30:57 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_std_io	*scan_std_io(char *placeholder)
{
	static t_std_io	*std_io;

	if (!placeholder)
		return (std_io);
	std_io = ft_calloc(1, sizeof(t_std_io));
	if (!std_io)
		exit_shell(MALLOC);
	std_io->std_in = -2;
	std_io->std_in = -2;
	std_io->curr_in = 1;
	std_io->curr_out = 0;
	std_io->in_saved = false;
	std_io->out_saved = false;
	return (std_io);
}