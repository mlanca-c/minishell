/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:45:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 13:54:30 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function initializes the main struct of the program - (t_ctrl *) 
 * controllers, once called by the main() function.
 * If the function is called with envp as NULL, then it's assumed that t_ctrl*
 * was already initialized. So instead of initializing the struct, the
 * init_controllers() function returns that already initialized struct.
 * This makes 'controllers' accessible anywhere in the program.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- t_ctrl*	- main variable of the program.
*/
t_ctrl	*init_controllers(char *envp[])
{
	static t_ctrl	*controllers = NULL;

	if (!envp)
		return (controllers);
	controllers = (t_ctrl *)malloc(sizeof(t_ctrl));
	if (!controllers)
		exit_shell();
	controllers->shell = SHELL;
	controllers->prompt = PROMPT;
	controllers->path = get_controllers_path(envp);
	controllers->home = get_controllers_home(envp);
	controllers->envp = get_controllers_envp(envp);
	return (controllers);
}

/*
 * This function creates a list containing all the arguments
 * of the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- t_lst*	- list of char containing all the envp arguments.
*/
t_list	**get_controllers_envp(char **envp)
{
	int		i;
	t_list	**lst_env;

	lst_env = (t_list **)malloc(sizeof(t_list **) * ft_arraylen(envp));
	if (!lst_env)
		exit_shell();
	i = 0;
	while (envp[i])
	{
		ft_lst_add_back(lst_env, ft_lst_new(envp[i]));
		i++;
	}
	return (lst_env);
}

/*
 * This function creates a char array containing all the paths to executable
 * files from the $PATH variable of the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- char**	- array of char containing all the paths to executable files.
*/
char	**get_controllers_path(char *envp[])
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (envp[i++])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	path = ft_split(&envp[i][5], ':');
	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		i++;
	}
	return (path);
}

/*
 * This function creates a char* containing the pathname of the user's home
 * directory from the $HOME variable of the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- char*	- string of characters containing the pathname of the user's home
 * 			directory.
*/
char	*get_controllers_home(char *envp[])
{
	int		i;
	char	*home;

	i = 0;
	while (envp[i++])
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			break ;
	home = ft_strjoin(&envp[i][5], "/");
	return (home);
}
