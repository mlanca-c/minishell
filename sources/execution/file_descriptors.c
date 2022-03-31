/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:51:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 21:14:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_descriptors(t_dlist *lst, int std_fd[2])
{
	t_info		*info;
	int			pipedes[2];
	static int	prev_fd = -2;

	while (lst)
	{
		info = ((t_cmd *)lst->content)->info;
		if(info->type == PIPE_OUT)
		{
			info->cur_fd[IN] = std_fd[IN];
			safe_keeping(pipe(pipedes));
			safe_keeping(dup2(pipedes[WRITE], STDOUT_FILENO));
			info->cur_fd[OUT] = pipedes[WRITE];
			prev_fd = pipedes[READ];
		}
		else if(info->type == PIPE_IN_OUT)
		{
			safe_keeping(dup2(prev_fd, STDIN_FILENO));
			info->cur_fd[IN] = prev_fd;
			safe_keeping(pipe(pipedes));
			safe_keeping(dup2(pipedes[WRITE], STDOUT_FILENO));
			info->cur_fd[OUT] = pipedes[WRITE];
			prev_fd = pipedes[READ];
		}
		else if(info->type == PIPE_IN)
		{
			info->cur_fd[OUT] = std_fd[OUT];
			safe_keeping(dup2(prev_fd, STDIN_FILENO));
			info->cur_fd[IN] = prev_fd;
			prev_fd = -2;
		}
		lst = lst->next;
	}
}
