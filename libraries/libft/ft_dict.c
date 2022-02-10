/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:42:50 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:11:09 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
	char *name = "aaa";
	char *value = "shit";
	int i = -1;
	
	t_dict	*dict;
	dict = NULL;
	ft_dict_add_back(&dict, ft_dict_new(name, (char *)value));
	printf("%s=\"%s\"\n", (char *)dict->key, (char *)dict->content);
	while (++i < 10)
	{
		ft_dict_add_back(&dict, ft_dict_new("User", (char *)value));
		printf("%s=\"%s\" - %d\n", (char *)dict->next->key, (char *)dict->next->content, i);
		dict = dict->next;
	}
	dict = ft_dict_front(dict);
	ft_dict_print(dict);
	ft_dict_clear(dict, free);
}