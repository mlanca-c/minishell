/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:19:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/15 13:30:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function creates a new element of an abstract syntax tree.
** The ft_ast_new() function allocates (with malloc()) and returns a new
** element.
** The variable 'content' is initialized with the value of the parameter
** 'content'. The variables 'right' and 'left' are initialized to null.
**
** @param	void	*content	- content to create the new element with.
**
** @return
** 		- The ft_ast_new() function returns the new element of the ast.
*/
t_ast	*ft_ast_new(void *content)
{
	t_ast	*tree;

	tree = (t_ast *)malloc(sizeof(t_ast));
	if (!tree)
		return (NULL);
	tree->content = content;
	tree->right = NULL;
	tree->left = NULL;
	return (tree);
}
