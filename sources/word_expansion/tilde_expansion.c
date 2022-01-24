/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:51:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/24 14:40:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_tilde(char *str);
char	*handle_tilde_in_assignment(char *str);

/* This function handles tilde expansion */
void	tilde_expansion(void **word)
{
	char	*str;
	int		i;

	if (!*word)
		return ;
	str = (char *)*word;
	i = ft_strfind(str, "=~");
	if (str[0] == '~')
		str = handle_tilde(str);
	else if (i > 0)
		str = handle_tilde_in_assignment(str);
	else
		return ;
	*word = (void *)str;
}

char	*handle_tilde(char *str)
{
	char	*f;

	f = str;
	str = ft_strjoin("$HOME", &str[1]);
	free(f);
	return (str);
}

char	*handle_tilde_in_assignment(char *str)
{
	int		i;
	char	*f;
	char	*sub;
	char	*join;

	i = ft_strfind(str, "=~");
	f = str;
	sub = ft_substr(f, 0, i + 1);	// remove ~
	join = ft_strjoin("$HOME", &str[i + 2]);
	str = ft_strjoin(sub, join);
	free(f);
	free(sub);
	free(join);
	return (str);
}
