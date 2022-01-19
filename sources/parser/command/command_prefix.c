/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:12:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 19:38:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_list(t_list **prefix, char *text);

t_list	*command_prefix(void)
{
	t_list	*prefix;

	prefix = NULL;
	while (true)
	{
		if (ft_strchr(scan_token(GET)->text, '='))
			add_list(&prefix, scan_token(GET)->text);
		else if (scan_token(GET)->type >= LESS
			&& scan_token(GET)->type <= DGREAT)
		{
			add_list(&prefix, scan_token(GET)->text);
			scan_token(NEXT);
			add_list(&prefix, scan_token(GET)->text);
		}
		else
			return (prefix);
		scan_token(NEXT);
	}
	return (NULL);
}

void	add_list(t_list **prefix, char *text)
{
	char	*str;

	str = ft_strdup(text);
	printf("adding %s to prefix list\n", str);
	ft_lst_add_back(prefix, ft_lst_new(str));
}
