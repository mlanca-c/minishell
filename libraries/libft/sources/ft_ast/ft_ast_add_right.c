/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:00 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/15 14:17:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ast_add_right(t_ast **root, t_ast *new)
{
	if (!(*root) || !new)
	{
		*root = new;
		return ;
	}
	(*root)->right = new;
}
