/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:05:41 by josantos          #+#    #+#             */
/*   Updated: 2022/03/11 18:26:43 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_ios(t_cmd *command, int index)
{
	bool	reset_in;
	bool	reset_out;
	
	save_ios(t_cmd *command, &reset_in, &reset_out);
	if (command->pipe && command->pipe != No_Pipe)
		set_pipes(command);
}

int	save_ios(t_commandbool reset_in, bool reset_out)
{
	
}