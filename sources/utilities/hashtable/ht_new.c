/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:59:32 by josantos          #+#    #+#             */
/*   Updated: 2022/02/06 22:59:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ht	*ht_new(void *content)
{
	t_ht	*ht;
	int		i;

	ht = (t_ht *)ft_calloc(1, sizeof(t_ht));
	if (!ht)
		return (NULL);
	i = ft_strfind(content, "=");
	ht->env_name = ft_substr(content, 0, i - 1);
	ht->env_val = ft_substr(content, i + 1, ft_strlen(content));
	ht->next = NULL;
	return (ht);
}
