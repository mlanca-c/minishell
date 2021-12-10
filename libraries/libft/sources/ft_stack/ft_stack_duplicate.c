/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:08:03 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/12 13:44:58 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function duplicates a stack.
** The ft_stack_duplicate() function copies a stack 'stack' and creates a
** duplicate of that stack 'duplicate'.
*/
t_stack	*ft_stack_duplicate(t_stack *stack)
{
	t_stack	*duplicate;
	t_stack	*new_node;

	duplicate = 0;
	while (stack)
	{
		new_node = ft_stack_new(stack->data);
		if (!new_node)
		{
			ft_stack_clear(&duplicate);
			return (0);
		}
		ft_stack_add_back(&duplicate, new_node);
		stack = stack->next;
	}
	return (duplicate);
}
