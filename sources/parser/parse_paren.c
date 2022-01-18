/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:39:21 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 01:19:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_paren(void)
{
	t_ast	*a;

	printf("parse_paren\n");
	if (scan_token(GET)->type == L_PAR)
	{
		a = parse_pipe();
		if (scan_token(GET)->type == R_PAR)
		{
			scan_token(UPDATE);
			return (a);
		}
	}
	else if (scan_token(GET)->type == WORD)
		return (parse_token());
	return (NULL);
}
