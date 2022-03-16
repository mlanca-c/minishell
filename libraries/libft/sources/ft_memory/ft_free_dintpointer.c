/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dintpointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:17:34 by josantos          #+#    #+#             */
/*   Updated: 2022/03/16 12:21:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_free_dintpointer(int **pipe)
{
	size_t	i;

	i = 0;
	while (pipe[i])
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
	return (NULL);
}
