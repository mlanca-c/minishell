/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:42:50 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:53:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
	t_dict	*dict;

	dict = NULL;
	for (int i = 0; i < 5; i++)
	{
		ft_dict_add_back(&dict, ft_dict_new(ft_strjoin("USER", ft_itoa(i)), ft_strdup("value")));
	}
	ft_dict_print(dict, "%s=\"%s\"\n");
	ft_dict_clear(dict, free);
	return (0);
}
