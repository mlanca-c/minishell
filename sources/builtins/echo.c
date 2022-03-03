/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:50:29 by josantos          #+#    #+#             */
/*   Updated: 2022/03/03 17:08:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	do_flag(char *flag, t_list *lst);

static void	do_flag(char *flag, t_list *lst)
{
	if (flag && ft_strncmp(flag, "n", ft_strlen(flag)))
		ft_lst_print(lst->next, " ");
	else
	{
		ft_lst_print(lst, " ");
		printf("\n");
	}
}

int	echo_builtin(t_cmd *command)
{
	char	*flag;
	t_list	*lst;

	lst = NULL;
	if (!command->suffix)
	{
		printf("\n");
		return (SUCCESS);
	}
	lst = command->suffix;
	flag = NULL;
	if (lst)
	{
		if (ft_strncmp(lst->content, "-n", 2) == 0)
		{
			flag = ft_strdup(lst->content + 1);
			lst = lst->next;
		}
		do_flag(flag, lst);
		free(flag);
	}
	else
		printf("\n");
	return (SUCCESS);
}
