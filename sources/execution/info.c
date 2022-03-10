/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:58:31 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 02:17:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_info	*scan_info(t_list *cmd)
{
	static t_cmd_info *info = NULL;
	
	if (!cmd)
		return (info);
	info = (t_cmd_info *)ft_calloc(1, sizeof(t_cmd_info));
	if (!info)
		exit_shell(MALLOC);
	info->lst_size = ft_lst_size(cmd);
	info->status = SUCCESS;
	info->index = 0;
	info->has_infile = false;
	info->has_outfile = false;
	return (info);
}