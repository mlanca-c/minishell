/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:34:12 by josantos          #+#    #+#             */
/*   Updated: 2022/03/09 21:34:05 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_redir(t_red *redirs)
{
	if (redirs->io_type == DLESS)
		return (do_heredoc(redirs));
	/*else if (redirs->io_type == GREAT || DGREAT)
		return (set_redir_out(redirs));
	else if (redirs->io_type == LESS)
		return (set_redir_in(redirs));
	else
		return (set_redir_pipe(redirs));*/
	return (SUCCESS);
}