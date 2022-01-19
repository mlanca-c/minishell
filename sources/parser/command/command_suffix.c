/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_suffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:40:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 19:47:33 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_list(t_list **prefix, char *text);

t_list	*command_suffix(void)
{
	t_list	*suffix;

	suffix = NULL;
	while (true)
	{
		if (scan_token(GET)->type == WORD)
			add_list(&suffix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			add_list(&suffix, scan_token(GET)->text);
			scan_token(NEXT);
			add_list(&suffix, scan_token(GET)->text);
		}
		else
			return (suffix);
		scan_token(NEXT);
	}
	return (NULL);
}
