/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2022/01/28 14:54:29 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_line(t_list *lst)
{
	while (lst)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}

void	do_flag(char *flag, t_list *lst)
{
	bool	valid = true;
	
	if (flag)
		{
			if (ft_strncmp(flag, "n", ft_strlen(flag)))
				valid = false;
			if (valid == false)
			{
				printf("%s ", flag);
				print_line(lst);
				printf("\n");
			}
			else
				print_line(lst);
		}
		else
		{
			print_line(lst);
			printf("\n");
		}
}

int	echo_builtin(t_cmd *cmd)
{
	char	*flag;
	t_list	*lst;

	lst = NULL;
	if (cmd->suffix)
		lst = cmd->suffix;
	flag = NULL;
	if (lst)
	{
		if (!ft_strncmp(lst->content, "-n", 2))
		{
			flag = lst->content + 1;
			lst = lst->next;
		}
		do_flag(flag, lst);
	}
	else
		printf("\n");
	return (SUCCESS);
}
