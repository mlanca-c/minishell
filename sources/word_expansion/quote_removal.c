/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:17:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/15 20:59:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *str);

char	*quote_removal(char *str)
{
	if (!str)
		return (NULL);
	if (ft_strfind(str, "\"") == -1 && ft_strfind(str, "\'") == -1)
		return (str);
	str = remove_quotes(str);
	return (str);
}

static char	*remove_quotes(char *str)
{
	char	*f;
	char	*key;
	char	*value;

	if (ft_strchr(str, '='))
	{
		key = ft_substr(str, 0, ft_strfind(str, "=") + 1);
		value = ft_substr(str, ft_strfind(str, "=") + 1,
				ft_strlen(str));
		f = value;
		value = ft_substr(value, 1, ft_strlen(value) - 2);
		free(f);
		f = str;
		str = ft_strjoin(key, value);
		free(f);
		free(key);
		free(value);
		return (str);
	}
	f = str;
	str = ft_substr(str, 1, ft_strlen(str) - 2);
	free(f);
	return (str);
}
