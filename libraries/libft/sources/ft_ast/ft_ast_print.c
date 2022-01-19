/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:23:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 12:51:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ast_print_rec(t_ast *root, int level)
{
	int	i;

	if (!root)
		return ;
	i = 0;
	while (i++ < level)
		printf(".");
	printf("%s\n", (char *)root->content);
	ft_ast_print_rec(root->left, level + 1);
	ft_ast_print_rec(root->right, level + 1);
}

/*
** This function prints all data from a ast.
** The ft_ast_print() function iterates the ast, and prints with printf()
** all the strings are followed by a breakline.
**
** @param	t_ast	*root	- root node of ast to iterate from.
*/
void	ft_ast_print(t_ast *root)
{
	ft_ast_print_rec(root, 0);
}
