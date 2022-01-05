/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:44:08 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/21 17:51:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is an operator test.
** The ft_isoperator() function tests for any of the following operators: '|',
** '<', '>' or '&'.
** If 'c' is any of the above mentioned, then the function returns 1.
** @param	int	c	- the character to be tested.
**
** @return
** 		- If the character is either '|' or '>' or '<' or '&', then the
**		ft_isoperator() function returns a non-zero integer. Else, a zero is
**		returned.
*/
int	ft_isoperator(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '&')
		return (1);
	return (0);
}
