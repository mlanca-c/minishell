/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:51:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 16:10:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function handles tilde expansion */
void	tilde_expansion(void **word)
{
	char	*str;

	if (!*word)
		return ;
	str = (char *)*word;
	if ((str[0] == '~' && !ft_strchr(str, '='))
		|| (ft_strfind(str, "=~") != -1))
	{
		if (ft_strfind(str, "~+/") >= 0)
			str = ft_str_replace(str, "~+", "$PWD");
		else if (ft_strfind(str, "~-/") >= 0)
			str = ft_str_replace(str, "~-", "$OLDPWD");
		else if (ft_strfind(str, "~/") >= 0)
			str = ft_str_replace(str, "~", "$HOME");
		else
			return ;
	}
	else
		return ;
	free(*word);
	*word = (void *)str;
}
