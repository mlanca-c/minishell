/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/03/03 14:39:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	check_dir(char *cd_arg);

int	cd_builtin(t_cmd *command)
{
	char	*pwd;

	pwd = scan_envp("PWD=", NULL);
	printf("ENTERING CD: %s\n", pwd);

	if (!command->suffix)
		chdir(scan_envp("HOME=", NULL));
	// else
	// {
	// 	if (check_dir(command->suffix->content))
	// 		return (BUILTIN_FAILURE);
	// 	if (ft_strlen(command->suffix->content) == 1
	// 		&& !ft_strncmp(command->suffix->content, "-", 1))
	// 		chdir(scan_old_pwd(NULL)[7]);
	// 	else
	// 		chdir(command->suffix->content);
	// }
	scan_envp("OLDPWD=", pwd);
	printf("OLDPWD=%s\n", scan_envp("OLDPWD=", NULL));
	scan_envp("PWD=", getcwd(NULL, 0));
	printf("PWD=%s\n", scan_envp("PWD=", NULL));
	// scan_old_pwd(scan_pwd(NULL));
	// scan_pwd(getcwd(NULL, 0));
	// printf("%s\n", scan_pwd(NULL));
	return (SUCCESS);
}

// static int	check_dir(char *cd_arg)
// {
// 	DIR		*checker;

// 	if (!ft_strncmp(cd_arg, "-", 1))
// 		checker = opendir(scan_old_pwd(NULL));
// 	else
// 		checker = opendir(cd_arg);
// 	if (!checker)
// 	{
// 		printf("shit\n");
// 		return (BUILTIN_FAILURE);
// 	}
// 	else
// 		return (0);
// }
