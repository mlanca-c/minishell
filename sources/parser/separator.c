/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:08:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:20:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_token_separator(t_token_t type)
{
	if (type == PIPE || type == AND_IF || type == OR_IF || type == L_PAR
		|| type == R_PAR)
		return (true);
	return (false);
}

// t_cmd_t	get_separator(t_list **token_list)
// {
// }

// void	separator_add_parser(t_ast *parser, t_cmd_t node)
// {
// }
