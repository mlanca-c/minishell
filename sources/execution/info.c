/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:58:31 by josantos          #+#    #+#             */
/*   Updated: 2022/02/23 13:03:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_info	*scan_info(t_list *cmd)
{
	static t_cmd_info *info = NULL;
	
	if (!cmd)
		return (info);
	info = ft_calloc(1, sizeof(t_cmd_info *));
	if (!info)
		exit_shell();
	info->lst_size = ft_lst_size(cmd);
	info->pipes = init_pipes(info);
	return (info);
}
