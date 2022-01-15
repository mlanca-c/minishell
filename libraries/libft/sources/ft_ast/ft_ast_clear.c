/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:54:00 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/15 14:00:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_ast_clear(t_ast *root)
{
	if (!root)
		return ;
	ft_ast_clear(root->left);
	ft_ast_clear(root->right);
	ft_ast_delete(root, free);
}

