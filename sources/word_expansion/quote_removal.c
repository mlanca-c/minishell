/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:17:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str);

void	quote_removal(void **word)
{
	char	*str;
	int		i;

	if (!*word)
		return ;
	str = ft_strdup((char *)*word);
	i = 0;
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
