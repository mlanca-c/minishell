/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:16:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 17:48:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester_minishell.h"

static char	*scan_name(void);
static int	scan_next(void);

int	main(int argc, char *argv[], char *envp[])
{
	int			i;
	int			state;
	t_tester	*tester;

	(void)argc;
	(void)argv;
	(void)envp;

	printf(GREEN"MINISHELL TESTER\n"RESET);
	tester = ft_calloc(1, sizeof(t_tester));
	if (!tester)
		return (1);
	tester->test_nbr = 30;
	i = 0;
	while (i < tester->test_nbr)
	{
		state = scan_next();
		if (!state)
		{
			printf(_TEST, scan_name(),_SUCCESS);
			tester->success++;
		}
		else
		{
			printf(_TEST, scan_name(),_FAILURE);
			printf(":%d\n", state - 1);
			tester->failure++;
		}
		i++;
	}

	printf(_SUCCESS);
	printf("%d/%d\n", tester->success, tester->test_nbr);
	printf(_FAILURE);
	printf("%d/%d\n", tester->failure, tester->test_nbr);
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
		exit(SUCCESS);
	status = fn[i++]();
	return (status);
}
