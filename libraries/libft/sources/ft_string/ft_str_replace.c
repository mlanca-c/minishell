/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:57:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 15:34:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *source, char *sub, char *with)
{
	char	*str;
	char	*f;
	char	*ssub;
	char	*join;
	int		i;

	if (!source)
		return (NULL);
	i = ft_strfind(source, sub);
	if (i == -1)
		return (NULL);
	str = ft_substr(source, 0, i);
	ssub = ft_substr(source, i + ft_strlen(sub), ft_strlen(source));
	join = ft_strjoin(with, ssub);
	f = str;
	str = ft_strjoin(str, join);
	free(join);
	free(ssub);
	free(f);
	return (str);
}
