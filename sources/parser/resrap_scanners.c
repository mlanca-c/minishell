/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_scanners.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:23:06 by josantos          #+#    #+#             */
/*   Updated: 2022/03/29 21:04:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function scans a t_node type from a parser_tree */
t_node	*scan_node(t_ast *parser_tree)
{
	if (!parser_tree)
		return (NULL);
	return ((t_node *)parser_tree->content);
}

t_cmd	*command_copy(t_cmd *command)
{
	t_cmd	*new;

	new = ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		exit_shell();
	if (command->name)
		new->name = ft_strdup(command->name);
	new->prefix = ft_dlst_copy(command->prefix, ft_dlst_size(command->prefix));
	new->suffix = ft_dlst_copy(command->suffix, ft_dlst_size(command->suffix));
	new->redirection = t_red_copy(command->redirection,
			ft_dlst_size(command->redirection));
	return (new);
}

/* This function scans a t_cmd type from a t_node */
t_dlist	*scan_command(t_cmd *command)
{
	static t_dlist	*command_list = NULL;
	t_dlist			*temporary;

	if (!command)
	{
		temporary = command_list;
		command_list = NULL;
		return (temporary);
	}
	ft_dlst_add_back(&command_list, ft_dlst_new(command_copy(command)));
	return (NULL);
}

t_dlist	*t_red_copy(t_dlist *origin, int end)
{
	int		i;
	t_red	*node;
	t_dlist	*list;
	t_red	*to_copy;

	if (!origin)
		return (NULL);
	if (end > ft_dlst_size(origin))
		end = ft_dlst_size(origin);
	i = 0;
	node = NULL;
	list = NULL;
	while (origin)
	{
		to_copy = (t_red *)origin->content;
		node = ft_calloc(1, sizeof(t_red));
		node->io_file = ft_strdup(to_copy->io_file);
		node->io_type = to_copy->io_type;
		ft_dlst_add_back(&list, ft_dlst_new(node));
		origin = origin->next;
		i++;
		if (i == end)
			return (list);
	}
	return (list);
}
