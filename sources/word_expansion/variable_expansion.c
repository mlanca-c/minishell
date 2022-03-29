/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:36:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 14:06:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_key(char *word);
static char	*get_value(char *key);

/* This function handles variable expansion */
char	*variable_expansion(char *str)
{
	char	*key;
	char	*val;
	char	*temp;

	if (!str)
		return (NULL);
	if (ft_strfind(str, "$") < 0 || str[0] == '\'')
		return (str);
	while (ft_strfind(str, "$") >= 0 && str[0] != '\'')
	{
		key = get_key(str);
		if (!key)
			return (str);
		if (ft_strcmp(key, "$?") == 0)
			val = ft_itoa(scan_controllers(NULL)->return_value);
		else
			val = get_value(&key[1]);
		temp = str;
		str = ft_str_replace(str, key, val);
		free(val);
		free(key);
		free(temp);
	}
	return (str);
}

static char	*get_value(char *key)
{
	if (!scan_envp(key, NULL))
		return (ft_strdup(""));
	else
		return (ft_strdup(scan_envp(key, NULL)));
}

static char	*get_key(char *str)
{
	char	*key;
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == '$')
			break ;
	if (ft_strcmp(str, "$?") == 0)
		return (ft_strdup("$?"));
	if (i != 0)
		key = ft_substr(str, i - 1, ft_strlen(str));
	else
		return (NULL);
	i = 0;
	while (key[++i])
		if (!ft_isalnum(key[i]) && key[i] != '_')
			break ;
	if (!key[i])
		return (key);
	temp = key;
	key = ft_substr(key, 0, i);
	free(temp);
	return (key);
}
