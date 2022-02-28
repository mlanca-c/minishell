/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:46:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 18:48:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	word_expansion_lst(t_list *argument);
static void	word_expansion_red(t_list *redirection);
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

/* This function handles word expansion of a t_list type */
static void	word_expansion_lst(t_list *argument)
{
	if (!argument)
		return ;
	while (argument)
	{
		argument->content = word_expansion_str((char *)argument->content);
		argument = argument->next;
	}
}

static void	word_expansion_red(t_list *redirection)
{
	t_red	*red;

	if (!redirection)
		return ;
	while (redirection)
	{
		red = redirection->content;
		red->io_file = word_expansion_str(red->io_file);
		redirection = redirection->next;
	}
}
