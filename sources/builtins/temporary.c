/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:44:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/22 13:55:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	temporary_builtin_redirection(t_list *lst)
{
	t_cmd	*command;

	while (lst)
	{
		command = (t_cmd *)lst->content;
		if (ft_strlen("echo") == ft_strlen(command->name)
			&& ft_strncmp("echo", command->name, ft_strlen(command->name)))
			echo_builtin(command);
		// else if (ft_strlen("cd") == ft_strlen(command->name)
			// && ft_strncmp("cd", command->name, ft_strlen(command->name)))
			// cd_builtin(command);
		// else if (ft_strlen("pwd") == ft_strlen(command->name)
			// && ft_strncmp("pwd", command->name, ft_strlen(command->name)))
			// pwd_builtin(command);
		// else if (ft_strlen("export") == ft_strlen(command->name)
			// && ft_strncmp("export", command->name, ft_strlen(command->name)))
			// export_builtin(command);
		// else if (ft_strlen("unset") == ft_strlen(command->name)
			// && ft_strncmp("unset", command->name, ft_strlen(command->name)))
			// unset_builtin(command);
		// else if (ft_strlen("env") == ft_strlen(command->name)
			// && ft_strncmp("env", command->name, ft_strlen(command->name)))
			// env_builtin(command);
		// else if (ft_strlen("exit") == ft_strlen(command->name)
			// && ft_strncmp("exit", command->name, ft_strlen(command->name)))
			// exit_builtin(command);
		lst = lst->next;
	}
}
