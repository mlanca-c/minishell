/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function focuses in freeing everything and exiting the program.
*/
void	exit_shell(void)
{
	t_ctrl	*controllers;
	t_err_t	error;

	controllers = scan_controllers(NULL);
	if (!controllers)
		exit(EXIT_FAILURE);
	error = controllers->error;
	free_controllers(controllers);
	if (error)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

/* This function frees the controllers - t_ctrl struct */
void	free_controllers(t_ctrl *controllers)
{
	if (controllers->envp)
		ft_dict_clear(controllers->envp, free);
	free(controllers);
}

/* This function frees a command - t_cmd */
void	free_command(void *cmd)
{
	t_cmd	*command;

	command = (t_cmd *)cmd;
	ft_lst_clear(command->prefix, free);
	free(command->name);
	ft_lst_clear(command->suffix, free);
	free(command);
}

/* This function frees the nodes from the parser_tree - t_ast */
void	free_node(void *ast_node)
{
	if (((t_node *)ast_node)->type == Simple_Command)
		free_command(((t_node *)ast_node)->cmd);
	free((t_node *)ast_node);
}

/* This function frees 'token' */
void	free_token(void *token)
{
	free(((t_token *)token)->text);
	free(token);
}
