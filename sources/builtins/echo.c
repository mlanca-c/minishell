/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2022/01/27 11:48:44 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}

int	echo_builtin(t_cmd *cmd)
{
	bool	valid = true;
	char	*flag;
	t_list	*lst;

	lst = NULL;
	if (cmd->suffix)
		lst = cmd->suffix;
	flag = NULL;
	if (lst)
	{
		if (!ft_strncmp(lst->content, "-", 1))
		{
			flag = lst->content;
			lst = lst->next;
		}
		if (flag)
		{
			if (!ft_strncmp(flag, "n", ft_strlen(flag)))
				valid = false;
			if (valid == false)
			{
				printf("%s", flag);
				echo_lst(lst);
				printf("\n");
			}
			else
				echo_lst(lst);
		}
		else
			echo_lst(lst);
	}
	else
		printf("\n");
	return (SUCCESS);
}
