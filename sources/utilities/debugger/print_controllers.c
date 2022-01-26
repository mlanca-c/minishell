/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controllers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:26:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 20:09:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function prints the t_ctrl struct */
void	print_controllers(void)
{
	int			i;
	t_ctrl		*controllers;
	static char	*err[] = {"(null)", NULL};

	controllers = init_controllers(NULL);
	printf("\n\n%s{ Controllers }\n", BLUE);
	printf(" [ Shell ]: %s\n", controllers->shell);
	printf(" [ Prompt ]: %s\n", controllers->prompt);
	printf(" [ Tokens ]: %p\n", &controllers->token_list);
	printf(" [ Parser ]: %p\n", &controllers->parser_tree);
	printf(" [ Env ]: %p\n", &controllers->envp);
	printf(" [ path ]:\n");
	i = 0;
	while (controllers->path[i])
		printf("\t%s\n", controllers->path[i++]);
	printf(" [ Home ]: %s\n", controllers->home);
	printf(" [ Directory ]: %s\n", controllers->directory);
	printf(" [ error ]: %s\n%s", err[controllers->error], RESET);
}
