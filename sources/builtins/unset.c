/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:18:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:02:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_cmd *command)
{
	char	*k;
	t_dlist	*lst;
	t_dict	*temp;
	t_dict	*envp;

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
