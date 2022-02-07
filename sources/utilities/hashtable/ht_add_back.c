/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:35:06 by josantos          #+#    #+#             */
/*   Updated: 2022/02/06 23:54:43 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ht_add_back(t_ht **ht, t_ht *new)
{
	t_ht	*tmp;

	tmp = *ht;
	if (!tmp)
		*ht = new;
	else
	{
		while ((tmp)->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
