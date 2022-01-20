/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:32:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 19:52:12 by mlanca-c         ###   ########.fr       */
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

	controllers = init_controllers(NULL);
	error = controllers->error;
	free_controllers(controllers);
	if (error)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

/* This function frees the controllers - t_ctrl struct */
void	free_controllers(t_ctrl *controllers)
{
	int		i;
	char	*path;

	free(controllers->home);
	i = 0;
	while (controllers->path[i])
	{
		path = controllers->path[i];
		free(path);
		i++;
	}
	free(controllers->path);
	free(controllers->directory);
	ft_lst_clear(controllers->envp, free);
	free(controllers);
}

/* This function frees the nodes from the parser_tree - t_ast */
void	free_node(void *ast_node)
{
	t_cmd	*cmd;
	t_node	*node;

	node = (t_node *)ast_node;
	if (node->type == Simple_Command)
	{
		cmd = (t_cmd *)node->cmd;
		ft_lst_clear(cmd->prefix, free);
		free(cmd->name);
		ft_lst_clear(cmd->suffix, free);
		free(cmd);
	}
	free(node);
}
