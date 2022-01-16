/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:33:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function focuses in freeing everything and exiting the program.
*/
void	exit_shell(void)
{
	exit(EXIT_FAILURE);
}

/*
 * This function frees the (t_list *) list of tokens.
*/
void	free_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	free(t->text);
	free(t);
}

void	free_assignment(t_assign *assignment)
{
	free(assignment->name);
	free(assignment->value);
	free(assignment);
}

/*
 * This function frees one command (t_cmd *c).
*/
void	free_command(t_cmd *command)
{
	if (command->name)
		free(command->name);
	ft_lst_clear(command->arguments, free);
	free(command->arguments);
	// if (command->redirection)
		// free(command->redirection);
}
