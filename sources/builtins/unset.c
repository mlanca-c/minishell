/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:18:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/23 16:34:27 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_cmd *command)
{
	char	*k;
	t_list	*lst;
	t_dict	*temp;
	t_dict	*envp;

	(void)temp;
	lst = command->suffix;
	envp = scan_controllers(NULL)->envp;
	while (lst)
	{
		temp = envp;
		k = ft_strjoin(lst->content, "=");
		while (envp)
		{
			if (!ft_strcmp(envp->key, k) || !ft_strcmp(envp->key, lst->content))
			{
				ft_dict_remove(&envp, free);
				break ;
			}
			envp = envp->next;
		}
		free(k);
		lst = lst->next;
		temp = envp;
	}
	return (SUCCESS);
}
