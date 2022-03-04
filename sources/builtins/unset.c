/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:18:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 18:55:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_cmd *command)
{
	char	*key;
	t_list	*lst;
	t_dict	*envp;

	if (!command->suffix)
		return (SUCCESS);
	lst = command->suffix;
	envp = scan_controllers(NULL)->envp;
	if (!envp)
		return (BUILTIN_FAILURE);
	while (lst)
	{
		key = ft_strjoin(lst->content, "=");
		while (envp)
		{
			if (ft_strncmp(envp->key, key, ft_strlen(envp->key)) == 0 ||
				ft_strncmp(envp->key, lst->content, ft_strlen(envp->key)) == 0)
			{
				ft_dict_remove(&envp, free);
				break ;
			}
			envp = envp->next;
		}
		free(key);
		lst = lst->next;
	}
	return (SUCCESS);
}
