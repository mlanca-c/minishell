/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:17:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 18:47:47 by josantos         ###   ########.fr       */
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

	f = str;
	str = ft_substr(str, 1, ft_strlen(str) - 2);
	free(f);
	return (str);
}
