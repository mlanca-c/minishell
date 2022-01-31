/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:17:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 16:23:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_removal(void **word)
{
	char	*str;
	int		i;

	if (!*word)
		return ;
	str = (char *)*word;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			str = remove_quotes(str, i);
		i++;
	}
	str = remove_quotes(str);
	free(*word);
	*word = (void *)str;
}

char	*remove_quotes(char *str, int i)
{
}
