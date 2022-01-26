/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:46:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/24 19:38:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function handles word expansion of a t_cmd type */
void	word_expansion(t_cmd *command)
{
	if (!command)
		return ;
	word_expansion_lst(command->prefix);
	word_expansion_str(&command->name);
	word_expansion_lst(command->suffix);
}

/*
 * Missing: command_substitution((void *)name);
 * Missing: filename_expansion((void *)name);
 * Missing: quote_removal((void *)name);
*/

/* This function handles word expansion of a char* type */
void	word_expansion_str(char **name)
{
	if (!name)
		return ;
	tilde_expansion((void *)name);
	variable_expansion((void *)name);
}

/* This function handles word expansion of a t_list type */
void	word_expansion_lst(t_list *argument)
{
	if (!argument)
		return ;
	while (argument)
	{
		tilde_expansion(&(argument->content));
		variable_expansion(&(argument->content));
		argument = argument->next;
	}
}