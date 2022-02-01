/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:17:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 10:33:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str);

void	quote_removal(void **word)
{
	char	*str;

	if (!*word)
		return ;
	str = ft_strdup((char *)*word);
	if (ft_strchr(str, '\"'))
		str = remove_quotes(str);
	free(*word);
	*word = (void *)str;
}

char	*remove_quotes(char *str)
{
	char	*f;

	f = str;
	str = ft_substr(str, 1, ft_strlen(str) -2);
	free(f);
	return (str);
}
