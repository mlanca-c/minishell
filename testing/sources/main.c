/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:16:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/22 12:40:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester_minishell.h"

t_tester	*tester;

static void	run_tests(void);
static void	status(void);
static void	success(void);
static void	failure(int state);

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	run_tests();
}

static void	run_tests(void)
{
	int	i;
	int	state;

	printf(GREEN"MINISHELL TESTER\n"RESET);
	tester = ft_calloc(1, sizeof(t_tester));
	if (!tester)
		return ;
	tester->test_nbr = 30;
	i = 0;
	while (i < tester->test_nbr)
	{
		state = scan_next();
		if (!state)
			success();
		else
			failure(state);
		i++;
	}
	status();
}

static void	success(void)
{
	printf(_TEST, scan_name(),_SUCCESS);
	tester->success++;
}

static void	failure(int state)
{
	printf(_TEST, scan_name(),_FAILURE);
	printf(":%d\n", state - 1);
	tester->failure++;
}

static void	status(void)
{
	printf(_SUCCESS);
	printf("%d/%d\n", tester->success, tester->test_nbr);
	printf(_FAILURE);
	printf("%d/%d\n", tester->failure, tester->test_nbr);
}
