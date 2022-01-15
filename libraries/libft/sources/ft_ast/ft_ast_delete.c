/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:54:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/15 13:57:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_ast_delete(t_ast *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	printf("freed %s\n", (char *)node->content);
	(*del)(node->content);
	free(node);
}
