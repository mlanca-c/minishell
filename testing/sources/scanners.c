/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:12:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/22 12:39:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_minishell.h"

char	*scan_name(void)
{
	static int	i = 0;
	static char	*type[] = {"controllers_get_envp", "scan_controllers",
		"scan_error", "scan_envp", "scan_path", "scan_directory", NULL};

	if (type[i])
		return (type[i++]);
	return (NULL);
}

int	scan_next(void)
{
	int				status;
	static int		i = 0;
	static test_fn	fn[] = {test_controllers_get_envp, test_scan_controllers,
		test_scan_error, test_scan_envp, test_scan_path, test_scan_directory,
		NULL};

	if (!fn[i])
		exit(SUCCESS);
	status = fn[i++]();
	return (status);
}
