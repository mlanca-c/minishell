/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:36:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/02 12:23:59 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_variable(char *word);
static char	*get_value(char *variable);

/* This function handles variable expansion */
char	*variable_expansion(char *str)
{
	char	*var;
	char	*val;
	char	*temp;

	if (!str)
		return (NULL);
	if (ft_strfind(str, "$") < 0 || str[0] == '\'')
		return (str);
	while (ft_strfind(str, "$") >= 0 && str[0] != '\'')
	{
		temp = str;
		var = get_variable(str);
		if (!var)
			return (str);
		val = get_value(var);
		if (!val)
			val = ft_strdup("");
		str = ft_str_replace(str, var, val);
		free(val);
		free(var);
		free(temp);
	}
	return (str);
}

static char	*get_value(char *variable)
{
	char	*temp;
	char	*result;
	int		i;

	temp = ft_strdup(variable);
	i = 0;
	while (i < (int)ft_strlen(variable))
	{
		if (!variable[i + 1])
			temp[i] = '=';
		else
			temp[i] = variable[i + 1];
		i++;
	}
	result = scan_envp(temp, NULL);
	free(temp);
	if (!result)
		return (NULL);
	return (ft_strdup(result));
}

static char	*get_variable(char *str)
{
	char	*var;
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == '$')
			break ;
	var = NULL;
	if (i != 0)
		var = ft_substr(str, i - 1, ft_strlen(str));
	if (!var[1])
	{
		free(var);
		return (NULL);
	}
	i = 0;
	while (var[++i])
		if (!ft_isalnum(var[i]))
			break ;
	if (!var[i])
		return (var);
	temp = var;
	var = ft_substr(var, 0, i);
	free(temp);
	return (var);
}
