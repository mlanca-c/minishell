/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:45:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/16 11:04:34 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	*controllers_get_envp(char *envp[])
{
	int		i;
	t_dict	*dict;
	char	*key;
	char	*value;

	dict = NULL;
	i = 0;
	key = NULL;
	value = NULL;
	while (envp[i])
	{
		key = ft_substr(envp[i], 0, ft_strfind(envp[i], "="));
		value = ft_substr(envp[i], ft_strfind(envp[i], "=") + 1,
				ft_strlen(envp[i]));
		ft_dict_add_back(&dict, ft_dict_new(key, value));
		i++;
	}
	return (dict);
}
