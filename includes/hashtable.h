/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:09:15 by josantos          #+#    #+#             */
/*   Updated: 2022/02/06 23:59:43 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

typedef struct s_hash_table
{
	struct s_hash_table	*next;
	char				*env_name;
	char				*env_val;
}	t_ht;

void	ht_add_back(t_ht **ht, t_ht *new);
t_ht	*ht_new(void *content);
void	ht_clear(t_ht *ht, void (*del)(void *));
void	ht_delete(t_ht *ht, void (*del)(void *));

#endif