/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:46:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 21:08:34 by mlanca-c         ###   ########.fr       */
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

/* This function handles word expansion of a char* type */
void	word_expansion_str(char **name)
{
	if (!name)
		return ;
	tilde_expansion((void *)name);
	variable_expansion((void *)name);
	filename_expansion((void *)name);
	quote_removal((void *)name);
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
		filename_expansion(&(argument->content));
		quote_removal(&(argument->content));
		argument = argument->next;
	}
}
