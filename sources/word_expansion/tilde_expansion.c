/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:51:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 16:49:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function handles tilde expansion */
char	*tilde_expansion(char *str)
{
	char	*temp;

	if (!str)
		return (str);
	if ((str[0] == '~' && !ft_strchr(str, '='))
		|| (ft_strfind(str, "=~") != -1))
	{
		temp = str;
		if (ft_strfind(str, "~+/") >= 0 || (ft_strlen(str) == 2
				&& str[0] == '~' && str[1] == '+'))
			str = ft_str_replace(str, "~+", "$PWD");
		else if (ft_strfind(str, "~-/") >= 0 || (ft_strlen(str) == 2
				&& str[0] == '~' && str[1] == '-'))
			str = ft_str_replace(str, "~-", "$OLDPWD");
		else if (ft_strfind(str, "~/") >= 0 || (ft_strlen(str) == 1
				&& str[0] == '~'))
			str = ft_str_replace(str, "~", "$HOME");
		else
			return (str);
		free(temp);
		return (str);
	}
	else
		return (str);
}
