/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:36:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 10:01:58 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_variable(char *word);
char	*get_value(char *variable);

/* This function handles variable expansion */
void	variable_expansion(void **word)
{
	char	*var;
	char	*val;
	char	*str;

	if (!*word)
		return ;
	str = (char *)*word;
	if (ft_strfind(str, "$") < 0 || str[0] == '\'')
		return ;
	while (ft_strfind(str, "$") >= 0 && str[0] != '\'')
	{
		var = get_variable(str);
		if (!var)
			return ;
		val = get_value(var);
		if (!val)
			str = ft_strdup("");
		else
			str = ft_str_replace(str, var, val);
		free(var);
		free(val);
		free(*word);
		*word = (void *)str;
	}
}

char	*get_simple_variable(char *variable)
{
	char	*f;

	f = variable;
	if (variable[1] == '{')
		f = ft_substr(f, 2, ft_strlen(f) - 3);
	else
		f = ft_substr(f, 1, ft_strlen(f));
	return (f);
}

char	*get_value(char *variable)
{
	t_list	*envp;
	char	*value;
	int		i;

	if (!variable)
		return (NULL);
	value = get_simple_variable(variable);
	variable = ft_strjoin(value, "=");
	free(value);
	i = ft_strlen(variable);
	envp = scan_controllers(NULL)->envp;
	while (envp)
	{
		value = (char *)envp->content;
		if (!ft_strncmp(value, variable, i))
		{
			free(variable);
			return (ft_substr(value, i, ft_strlen(value)));
		}
		envp = envp->next;
	}
	return (NULL);
}

char	*get_variable_helper(char *var, int b)
{
	int		i;
	char	*f;

	i = b + 1;
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && !b)
			break ;
		if (b && var[i] == '}')
		{
			i++;
			break ;
		}
		i++;
	}
	f = var;
	var = ft_substr(var, 0, i);
	free(f);
	if (!var[0])
	{
		free(var);
		return (NULL);
	}
	return (var);
}

char	*get_variable(char *word)
{
	int		i;
	int		b;
	char	*var;

	if (!word)
		return (NULL);
	i = 0;
	while (word[i])
	{
		if (word[i] == '$')
			break ;
		i++;
	}
	var = ft_substr(word, i, strlen(word));
	if (!var[0])
	{
		free(var);
		return (NULL);
	}
	b = 0;
	if (var[1] == '{')
		b = 1;
	return (get_variable_helper(var, b));
}
