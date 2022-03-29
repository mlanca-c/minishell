/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:46:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 21:03:04 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	word_expansion_lst(t_dlist *argument);
static void	word_expansion_red(t_dlist *redirection);
static char	*word_expansion_str(char *name);

/* This function handles word expansion of a t_cmd type */
void	word_expansion(t_cmd *command)
{
	if (!command)
		return ;
	word_expansion_lst(command->prefix);
	command->name = word_expansion_str(command->name);
	word_expansion_lst(command->suffix);
	word_expansion_red(command->redirection);
}

/* This function handles word expansion of a char* type */
static char	*word_expansion_str(char *name)
{
	if (!name)
		return (NULL);
	name = tilde_expansion(name);
	name = variable_expansion(name);
	name = filename_expansion(name);
	name = quote_removal(name);
	return (name);
}

/* This function handles word expansion of a t_dlist type */
static void	word_expansion_lst(t_dlist *argument)
{
	if (!argument)
		return ;
	while (argument)
	{
		argument->content = word_expansion_str((char *)argument->content);
		argument = argument->next;
	}
}

static void	word_expansion_red(t_dlist *redirection)
{
	t_red	*red;
	t_dlist	*temp;
	t_dlist	*lst;

	if (!redirection)
		return ;
	lst = t_red_copy(redirection, ft_dlst_size(redirection));
	temp = lst;
	while (temp)
	{
		red = temp->content;
		red->io_file = word_expansion_str(red->io_file);
		temp = temp->next;
	}
	ft_dlst_clear(lst, free_redirection);
}
