/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:57:04 by josantos          #+#    #+#             */
/*   Updated: 2022/02/07 00:00:29 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ht_delete(t_ht *ht, void (*del)(void *))
{
	if (!ht || !del)
		return ;
	(*del)(ht->env_name);
	(*del)(ht->env_val);
	free(ht);
}