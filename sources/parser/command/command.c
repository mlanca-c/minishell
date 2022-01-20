/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:36:05 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 19:36:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*command(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	cmd->prefix = command_prefix();
	if (scan_token(GET)->type == WORD)
	{
		cmd->name = ft_strdup(scan_token(GET)->text);
		scan_token(NEXT);
	}
	cmd->suffix = command_suffix();
	return (cmd);
}
