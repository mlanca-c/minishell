/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_word_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:45:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/01 10:25:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester_minishell.h"

int	test_tilde_expansion(void)
{
	char	*str;

	str = tilde_expansion("sources/");
	if (ft_strncmp(str, "sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("sources/"))
		return (NAY + 1);

	str = tilde_expansion(ft_strdup("~/sources/"));
	if (ft_strncmp(str, "$HOME/sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("$HOME/sources/"))
		return (NAY + 2);

	str = tilde_expansion(ft_strdup("~-/sources/"));
	if (ft_strncmp(str, "$OLDPWD/sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("$OLDPWD/sources/"))
		return (NAY + 3);

	str = tilde_expansion(ft_strdup("~+/sources/"));
	if (ft_strncmp(str, "$PWD/sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("$PWD/sources/"))
		return (NAY + 4);

	return (YAY);
}

int	test_variable_expansion(void)
{
	char	*str;
	char	**envp;
	t_ctrl	*controllers;

	envp = ft_split("USER=mlanca-c HOME=/home/mlanca-c PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell OLDPWD=/lv3/Minishell/sources", ' ');
	controllers = scan_controllers(envp);

	str = variable_expansion(ft_strdup("sources/"));
	if (ft_strncmp(str, "sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("sources/"))
		return (NAY + 1);
	free(str);

	str = variable_expansion(ft_strdup("$"));
	if (ft_strncmp(str, "$", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("$"))
		return (NAY + 2);
	free(str);

	str = variable_expansion(ft_strdup("My path $USER path"));
	if (ft_strncmp(str, "My path mlanca-c path", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("My path mlanca-c path"))
		return (NAY + 3);
	free(str);

	str = tilde_expansion(ft_strdup("~/sources/"));
	str = variable_expansion(str);
	if (ft_strncmp(str, "/home/mlanca-c/sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("/home/mlanca-c/sources/"))
		return (NAY + 4);
	free(str);

	str = variable_expansion(ft_strdup("$PWD"));
	if (ft_strncmp(str, "/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell"))
		return (NAY + 5);
	free(str);

	str = variable_expansion(ft_strdup("$GIBERISH"));
	if (ft_strncmp(str, "", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen(""))
		return (NAY + 6);
	free(str);

	str = variable_expansion(ft_strdup("Hello $GIBERISH Hello"));
	if (ft_strncmp(str, "Hello  Hello", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("Hello  Hello"))
		return (NAY + 6);
	free(str);

	str = variable_expansion(ft_strdup("$PWD $OLDPWD $USER"));
	if (ft_strncmp(str, "/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell /lv3/Minishell/sources mlanca-c", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell /lv3/Minishell/sources mlanca-c"))
		return (NAY + 7);
	free(str);

	str = variable_expansion(ft_strdup("$PWD $OLDPWD $USER helps $GIBERISH"));
	if (ft_strncmp(str, "/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell /lv3/Minishell/sources mlanca-c helps ", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell /lv3/Minishell/sources mlanca-c helps "))
		return (NAY + 8);
	free(str);

	return (YAY);
}

int	test_filename_expansion(void)
{
	char	*str;

	str = filename_expansion(ft_strdup("sources/"));
	if (ft_strncmp(str, "sources/", ft_strlen(str)) != 0
		|| ft_strlen(str) != ft_strlen("sources/"))
		return (NAY + 1);
	free(str);

	str = filename_expansion(ft_strdup("HSHS*"));
	if (ft_strlen(str) != ft_strlen("HSHS*"))
		return (NAY + 2);
	free(str);

	str = filename_expansion(ft_strdup("so*"));
	if (ft_strlen(str) != ft_strlen("sources"))
		return (NAY + 3);
	free(str);

	str = filename_expansion(ft_strdup("so*urces"));
	if (ft_strlen(str) != ft_strlen("sources"))
		return (NAY + 4);
	free(str);

	str = filename_expansion(ft_strdup("*urces"));
	if (ft_strlen(str) != ft_strlen("sources"))
		return (NAY + 5);
	free(str);

	str = filename_expansion(ft_strdup("so*ources"));
	if (ft_strlen(str) != ft_strlen("sources"))
		return (NAY + 6);
	free(str);

	return (YAY);
}

int	test_quote_removal(void)
{
	char	*str;

	str = quote_removal(ft_strdup("Hello World"));
	if (ft_strncmp(str, "Hello World", ft_strlen(str))
		|| ft_strlen(str) != ft_strlen("Hello World"))
		return (NAY + 1);
	free(str);

	str = quote_removal(ft_strdup("\"Hello $USER World\""));
	if (ft_strncmp(str, "Hello $USER World", ft_strlen(str))
		|| ft_strlen(str) != ft_strlen("Hello $USER World"))
		return (NAY + 2);
	free(str);

	str = quote_removal(ft_strdup("\'Hello World\'"));
	if (ft_strncmp(str, "Hello World", ft_strlen(str))
		|| ft_strlen(str) != ft_strlen("Hello World"))
		return (NAY + 3);
	free(str);

	return (YAY);
}
