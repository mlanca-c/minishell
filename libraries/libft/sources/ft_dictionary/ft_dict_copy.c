/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:libraries/libft/sources/ft_dictionary/ft_dict_copy.c
/*   ft_dict_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:17:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/03 16:35:03 by mlanca-c         ###   ########.fr       */
=======
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:03:57 by josantos          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:37 by mlanca-c         ###   ########.fr       */
>>>>>>> main:libraries/libft/sources/ft_dictionary/ft_dict_remove.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD:libraries/libft/sources/ft_dictionary/ft_dict_copy.c
t_dict	*ft_dict_copy(t_dict *dict)
{
	t_dict	*new;

	if (!dict)
		return (NULL);
	new = NULL;
	while (dict)
	{
		if (!dict->content)
			ft_dict_add_back(&new, ft_dict_new(ft_strdup(dict->key), NULL));
		else
			ft_dict_add_back(&new, ft_dict_new(ft_strdup(dict->key),
				ft_strdup(dict->content)));
		dict = dict->next;
	}
	return (new);
=======
void	ft_dict_remove(t_dict **dict)
{
	t_dict	*temp;

	if (!dict)
		return ;
	temp = *dict;
	if (temp->next)
		temp->next->previous = temp->previous;
	if (temp->previous)
		temp->previous->next = temp->next;
	if (temp->previous)
		*dict = temp->previous;
	else
		*dict = temp->next;
	free(temp);
>>>>>>> main:libraries/libft/sources/ft_dictionary/ft_dict_remove.c
}
