/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controllers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:26:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/28 15:02:43 by josantos         ###   ########.fr       */
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
	printf(" [ Current Directory ]: %s\n", controllers->dir_path);
	printf(" [ Previous Directory ]: %s\n", controllers->prev_dir);
	printf(" [ error ]: %s\n%s", err[controllers->error], RESET);
}
