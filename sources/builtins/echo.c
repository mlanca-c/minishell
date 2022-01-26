/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2022/01/26 10:55:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(t_cmd *cmd)
{
	size_t	i;
	bool	valid = true;
	char	*flag;
	t_list	*lst;

	i = 0;
	lst = cmd->suffix;
	if (ft_strncmp(cmd->suffix->content, "-", 1))
	{
		flag = cmd->suffix->content;
		lst = lst->next;
	}
	if (flag)
	{
		while (++i < ft_strlen(flag))
			if (ft_strncmp(&flag[i], "n", 1))
				valid = false;
		if (valid == false)
		{
			printf("%s", flag);
			print_command_lst(lst);
			printf("\n");
		}
		else
			print_command_lst(lst);
	}
	else
		print_command_lst(lst);
	return (SUCCESS);
}
