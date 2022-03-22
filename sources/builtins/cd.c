/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/03/22 16:48:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_minus(void);

int	cd_builtin(t_cmd *command)
{	
	if (!command->suffix)
		chdir(scan_envp("HOME", NULL));
	else if (ft_strncmp(command->suffix->content, "-",
			ft_strlen(command->suffix->content)) == 0)
		return (handle_minus());
	else if (opendir(command->suffix->content))
		chdir(command->suffix->content);
	else
	{
		builtin_err(command, "No such file or directory");
		return (FAILURE);
	}
	scan_envp("OLDPWD", ft_strdup(scan_envp("PWD", NULL)));
	scan_envp("PWD", getcwd(NULL, 0));
	return (SUCCESS);
}

static int	handle_minus(void)
{
	t_dict	*envp;

	envp = scan_controllers(NULL)->envp;
	if (opendir(scan_envp("OLDPWD", NULL)))
	{
		chdir(scan_envp("OLDPWD", NULL));
		printf("%s\n", scan_envp("OLDPWD", NULL));
	}
	else
	{
		printf("crash: cd: OLDPWD not set\n");
		if (!ft_dict_key_exists(envp, "OLDPWD"))
			ft_dict_add_back(&envp, ft_dict_new(ft_strdup("OLDPWD"), NULL));
		return (FAILURE);
	}
	return (SUCCESS);
}
