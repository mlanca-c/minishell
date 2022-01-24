/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:46:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/23 13:41:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	word_expansion(t_cmd *command)
{
	if (!command)
		return ;
	word_expansion_lst(command->prefix);
	word_expansion_str(&command->name);
	word_expansion_lst(command->suffix);
}

void	word_expansion_str(char **name)
{
	if (!name)
		return ;
	tilde_expansion((void *)name);
	variable_expansion((void *)name);
	// command_substitution((void *)name);
	// filename_expansion((void *)name);
	// quote_removal((void *)name);
}

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
