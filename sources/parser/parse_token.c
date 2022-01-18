/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:47:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 01:16:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_token(void)
{
	static char	*type[] = {"Simple Command", "Pipeline", "Here-Document", "And",
		"Or", NULL};
	t_token	*token;

	token = scan_token(GET);
	printf("parse_token: \n"); print_token(token);
	// printf("get: "); print_token(token);
	if (token->type == PIPE)
		return (ft_ast_new(ft_strdup(type[1])));
	if (token->type == DLESS)
		return (ft_ast_new(ft_strdup(type[2])));
	if (token->type == AND_IF)
		return (ft_ast_new(ft_strdup(type[3])));
	if (token->type == OR_IF)
		return (ft_ast_new(ft_strdup(type[4])));
	return (ft_ast_new(ft_strdup(token->text)));
}
