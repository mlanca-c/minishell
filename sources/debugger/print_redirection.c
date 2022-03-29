/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:11:29 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:02:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_redirection_template(t_red *redirection);

void	print_redirections(t_cmd *command)
{
	t_dlist	*lst;

	lst = command->redirection;
	while (lst)
	{
		print_redirection_template((t_red *)lst->content);
		lst = lst->next;
	}
}

static void	print_redirection_template(t_red *redirection)
{
	static char	*type[] = {"<", ">", "<<", ">>", NULL};

	printf("  [ io_type ]: %s\n", type[redirection->io_type - 2]);
	printf("  [ io_file ]: %s\n\n", redirection->io_file);
}
