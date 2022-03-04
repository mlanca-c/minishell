/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:16:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/04 18:34:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester_minishell.h"

static char	*scan_name(void);
static int	scan_next(void);

int	main(int argc, char *argv[], char *envp[])
{
	int	state;
	int	failure;
	int	success;

	(void)argc;
	(void)argv;
	(void)envp;

	printf(GREEN"MINISHELL TESTER\n"RESET);
	failure = 0;
	success = 0;
	while (true)
	{
		state = scan_next();
		if (state == -1)
			break ;
		if (!state)
		{
			printf(_TEST, scan_name(),_SUCCESS);
			success++;
		}
		else
		{
			printf(_TEST, scan_name(),_FAILURE);
			printf(":%d\n", state - 1);
			failure++;
		}
	}
	printf("%60s"_SUCCESS, " ");
	printf("%60s%d/%d \n", " ",success, success + failure);
	printf("%60s"_FAILURE"\n", " ");
	printf("%60s%d/%d \n", " ", failure, success + failure);
}
static char	*scan_name(void)
{
	static int	i = 0;
	static char	*type[] = {"controllers_get_envp", "scan_controllers",
		"scan_error", "scan_envp", "scan_path", "scan_directory",
		"test_tilde_expansion", "test_variable_expansion",
		"test_filename_expansion", "test_quote_removal", NULL};

	if (type[i])
		return (type[i++]);
	return (NULL);
}

static int	scan_next(void)
{
	int				status;
	static int		i = 0;
	static test_fn	fn[] = {test_controllers_get_envp, test_scan_controllers,
		test_scan_error, test_scan_envp, test_scan_path, test_scan_directory,
		test_tilde_expansion, test_variable_expansion, test_filename_expansion,
		test_quote_removal, NULL};

	if (!fn[i])
		return (-1);
	status = fn[i++]();
	return (status);
}
