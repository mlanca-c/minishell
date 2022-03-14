/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:03:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/03 16:03:44 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dict	*ft_merge_sort(t_dict *first, t_dict *second);
static t_dict	*ft_dict_split(t_dict *head);

void	ft_dict_sort(t_dict **dict)
{
	t_dict	*first;
	t_dict	*second;

	first = *dict;
	if (!first || !first->next)
		return ;
	second = ft_dict_split(first);
	ft_dict_sort(&first);
	ft_dict_sort(&second);
	*dict = ft_merge_sort(first, second);
}

static t_dict	*ft_merge_sort(t_dict *first, t_dict *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (ft_strcmp(first->key, second->key) < 0)
	{
		first->next = ft_merge_sort(first->next, second);
		first->next->previous = first;
		first->previous = NULL;
		return (first);
	}
	else
	{
		second->next = ft_merge_sort(first, second->next);
		second->next->previous = second;
		second->previous = NULL;
		return (second);
	}
}

static t_dict	*ft_dict_split(t_dict *head)
{
	t_dict	*slow;
	t_dict	*fast;
	t_dict	*temporary;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temporary = slow->next;
	slow->next = 0;
	return (temporary);
}
