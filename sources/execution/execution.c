/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 21:12:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_dlist *lst)
{
	int	std_fd[2];

	std_fd[IN] = safe_keeping(dup(STDIN_FILENO));
	std_fd[OUT] = safe_keeping(dup(STDOUT_FILENO));
	init_info(lst, std_fd);
	lst = ft_dlst_last(lst);
	while (lst)
	{
		print_info((t_cmd *)lst->content);
		// execute_command((t_cmd *)lst->content, std_fd);
		lst = lst->previous;
	}
	lst = ft_dlst_first(lst);
}
