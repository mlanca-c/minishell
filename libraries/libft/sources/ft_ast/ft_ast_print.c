/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:23:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/15 13:47:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ast_print_rec(t_ast *root, int level)
{
	if (!root)
		return ;
	for (int i = 0; i < level; i++)
		ft_putstr_fd("  ", 1);
	ft_putstr_fd((char *)root->content, 1);
	ft_putstr_fd("\n", 1);
	ft_ast_print_rec(root->left, level + 1);
	ft_ast_print_rec(root->right, level + 1);
}

/*
** This function prints all data from a ast.
** The ft_ast_print() function iterates the ast, and prints with ft_putstr_fd()
** all the strings are followed by a breakline.
**
** @param	t_ast	*root	- root node of ast to iterate from.
*/
void	ft_ast_print(t_ast *root)
{
	ft_ast_print_rec(root, 0);
}
