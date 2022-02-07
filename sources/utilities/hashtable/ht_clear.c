/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:05:55 by josantos          #+#    #+#             */
/*   Updated: 2022/02/06 23:58:44 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ht_clear(t_ht *ht, void (*del)(void *))
{
	if (!ht)
		return ;
	ht_clear(ht->next, del);
	ht_delete(ht, del);
}