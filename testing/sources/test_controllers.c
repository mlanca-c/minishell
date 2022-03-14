/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_controllers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:09:43 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 16:20:44 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_minishell.h"

int	test_scan_controllers(void)
{
	char	*envp[] = {NULL};
	t_ctrl	*controllers;

	/* test 1 */
	if (scan_controllers(NULL))
		return (NAY + 1);

	/* test 2 */
	controllers = scan_controllers(envp);
	if (!controllers)
		return (NAY + 2);

	/* freeing memory of tester function */
	free_controllers(controllers);

	return (YAY);
}

int	test_scan_error(void)
{
	char	**envp;
	t_ctrl	*controllers;

	envp = ft_split("USER=mlanca-c HOME=/home/mlanca-c PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell OLDPWD=/lv3/Minishell/sources", ' ');
	controllers = scan_controllers(envp);


	/* test 1 */
	if (scan_error(NULL))
		return (NAY + 1);

	/* test 2 */
	if (scan_error((void *)null))
		return (NAY + 2);

	/* Freeing allocated memory of tester function */
	int	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	free_controllers(controllers);

	return (YAY);
}

int	test_scan_envp(void)
{
	char	**envp;
	t_ctrl	*controllers;

	envp = ft_split("USER=mlanca-c HOME=/home/mlanca-c PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell OLDPWD=/lv3/Minishell/sources", ' ');
	controllers = scan_controllers(envp);

	/* test 1 */
	if (!controllers)
		return (NAY + 1);

	/* test 2 */
	if (!controllers->envp)
		return (NAY + 2);

	/* test 3 */
	if (!scan_envp("USER=", NULL))
		return (NAY + 3);

	/* test 4 */
	if (ft_strncmp(scan_envp("USER=", NULL), "mlanca-c", ft_strlen("mlanca-c")) != 0
		|| ft_strlen("mlanca-c") != ft_strlen(scan_envp("USER=", NULL)))
		return (NAY + 4);

	/* test 5 */
	if (!scan_envp("HOME=", NULL))
		return (NAY + 5);

	/* test 6 */
	if (ft_strncmp(scan_envp("HOME=", NULL), "/home/mlanca-c", ft_strlen("/home/mlanca-c")) != 0
		|| ft_strlen("/home/mlanca-c") != ft_strlen(scan_envp("HOME=", NULL)))
		return (NAY + 6);

	/* test 7 */
	if (!scan_envp("PATH=", NULL))
		return (NAY + 7);

	/* test 8 */
	if (ft_strncmp(scan_envp("PATH=", NULL), "/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", ft_strlen("/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin")) != 0
		|| ft_strlen("/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin") != ft_strlen(scan_envp("PATH=", NULL)))
		return (NAY + 8);

	/* test 9 */
	if (!scan_envp("PWD=", NULL))
		return (NAY + 9);

	/* test 10 */
	if (ft_strncmp(scan_envp("PWD=", NULL), "/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell", ft_strlen("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell")) != 0
		|| ft_strlen("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell") != ft_strlen(scan_envp("PWD=", NULL)))
		return (NAY + 10);

	/* test 11 */
	if (!scan_envp("USER=", ft_strdup("")))
		return (NAY + 11);

	/* test 12 */
	if (ft_strncmp(scan_envp("USER=", NULL), "", ft_strlen("")) != 0
		|| ft_strlen("") != ft_strlen(scan_envp("USER=", NULL)))
		return (NAY + 12);

	/* test 13 */
	if (scan_envp("NULL=", NULL))
		return (NAY + 13);

	/* test 14 */
	if (scan_envp("NULL=", NULL))
		return (NAY + 14);

	/* test 15 */
	if (ft_strncmp(scan_envp("PWD=", ft_strdup(scan_envp("OLDPWD=", NULL))), "/lv3/Minishell/sources", ft_strlen("/lv3/Minishell/sources")) != 0
		|| ft_strlen("/lv3/Minishell/sources") != ft_strlen(scan_envp("PWD=", NULL)))
		return (NAY + 15);

	/* test 16 */
	char	*cwd;
	cwd = getcwd(NULL, 0);
	if (ft_strncmp(scan_envp("PWD=", ft_strdup(cwd)), cwd, ft_strlen(cwd)) != 0
		|| ft_strlen(cwd) != ft_strlen(scan_envp("PWD=", NULL)))
		return (NAY + 16);
	free(cwd);

	/* Freeing allocated memory of tester function */
	int	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	free_controllers(controllers);

	return (YAY);
}

int	test_scan_path(void)
{
	char	**envp;
	char	**path;
	t_ctrl	*controllers;

	envp = ft_split("PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games", ' ');
	controllers = scan_controllers(envp);

	/* test 1 */
	if (!controllers)
		return (NAY + 1);

	/* test 2 */
	path = scan_path();
	if (!path)
		return (NAY + 2);

	/* test 3 */
	if (ft_strncmp(path[0], "/home/mlanca-c/.local/bin/", ft_strlen(path[0])) != 0
		|| ft_strlen("/home/mlanca-c/.local/bin/") != ft_strlen(path[0]))
		return (NAY + 3);

	/* test 4 */
	if (ft_strncmp(path[1], "/usr/local/sbin/", ft_strlen(path[1])) != 0
		|| ft_strlen("/usr/local/sbin/") != ft_strlen(path[1]))
		return (NAY + 4);

	/* test 5 */
	if (ft_strncmp(path[2], "/usr/local/bin/", ft_strlen(path[2])) != 0
		|| ft_strlen("/usr/local/bin/") != ft_strlen(path[2]))
		return (NAY + 5);

	/* test 6 */
	if (ft_strncmp(path[3], "/usr/sbin/", ft_strlen(path[3])) != 0
		|| ft_strlen("/usr/sbin/") != ft_strlen(path[3]))
		return (NAY + 6);

	/* test 7 */
	if (ft_strncmp(path[4], "/usr/bin/", ft_strlen(path[4])) != 0
		|| ft_strlen("/usr/bin/") != ft_strlen(path[4]))
		return (NAY + 7);

	/* test 8 */
	if (ft_strncmp(path[5], "/sbin/", ft_strlen(path[5])) != 0
		|| ft_strlen("/sbin/") != ft_strlen(path[5]))
		return (NAY + 8);

	/* test 9 */
	if (ft_strncmp(path[6], "/bin/", ft_strlen(path[6])) != 0
		|| ft_strlen("/bin/") != ft_strlen(path[6]))
		return (NAY + 9);

	/* test 10 */
	if (ft_strncmp(path[7], "/usr/games/", ft_strlen(path[7])) != 0
		|| ft_strlen("/usr/games/") != ft_strlen(path[7]))
		return (NAY + 10);

	/* test 11 */
	if (path[8])
		return (NAY + 11);

	/* Freeing allocated memory of tester function */
	int	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	scan_envp("PATH=", ft_strdup("/usr/games"));
	path = scan_path();

	/* test 12 */
	if (!path)
		return (NAY + 12);

	/* test 13 */
	if (ft_strncmp(path[0], "/usr/games/", ft_strlen(path[0])) != 0
		|| ft_strlen("/usr/games/") != ft_strlen(path[0]))
		return (NAY + 13);

	/* test 14 */
	if (path[1])
		return (NAY + 14);

	/* Freeing allocated memory of tester function */
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	free_controllers(controllers);
	return (YAY);
}

int	test_scan_directory(void)
{
	char	**envp;
	t_ctrl	*controllers;

	envp = ft_split("PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell", ' ');
	controllers = scan_controllers(envp);

	/* test 1 */
	if (!controllers)
		return (NAY + 1);

	/* test 2 */
	if (ft_strncmp("Minishell", scan_directory(), ft_strlen("Minishell")) != 0
		|| ft_strlen(scan_directory()) != ft_strlen("Minishell"))
		return (NAY + 2);

	/* test 3 */
	scan_envp("PWD=", ft_strdup("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell/sources"));
	if (ft_strncmp("sources", scan_directory(), ft_strlen("sources")) != 0
		|| ft_strlen(scan_directory()) != ft_strlen("sources"))
		return (NAY + 3);

	/* Freeing allocated memory of tester function */
	int	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	free_controllers(controllers);

	return (YAY);
}

int	test_controllers_get_envp(void)
{
	char	**envp;
	t_dict	*dict;

	envp = ft_split("USER=mlanca-c HOME=/home/mlanca-c PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell", ' ');
	dict = controllers_get_envp(envp);

	/* test 1 */
	if (!dict)
		return (NAY + 1);

	/* test 2 */
	if (ft_dict_size(dict) != 4)
		return (NAY + 2);

	/* Freeing allocated memory of tester function */
	int	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	ft_dict_clear(dict, free);

	return (YAY);
}
