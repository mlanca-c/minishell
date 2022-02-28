/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_controllers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:26:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/21 10:40:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_minishell.h"

int	test_controllers_get_envp(void)
{
	char	**envp;
	t_dict	*dict;

	envp = ft_split("USER=mlanca-c HOME=/home/mlanca-c PATH=/home/mlanca-c/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin PWD=/home/mlanca-c/Desktop/42lisboa/42cursus/lv3/Minishell", ' ');
	dict = controllers_get_envp(envp);
	if (!dict)
		return (NAY + 1);
	if (ft_dict_size(dict) != 4)
		return (NAY + 2);
	return (YAY);
}
