/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isoperator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:28:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 10:30:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*/
int	ft_str_isoperator(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isoperator(str[i]))
			return (0);
		i++;
	}
	return (1);
}

