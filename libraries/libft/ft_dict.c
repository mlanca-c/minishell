/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:42:50 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 12:09:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
	char *name = "aaa";
	char *value = "bbb";
	t_dict	*dict;
	dict = NULL;
	ft_dict_add_back(&dict, ft_dict_new(name, value));
	printf("%s=\"%s\"", (char *)dict->key, (char *)dict->content);
	value = "asfsa";
	ft_dict_add_back(&dict, ft_dict_new("User", value));
	printf("%s=\"%s\"", (char *)dict->next->key, (char *)dict->next->content);

	
}