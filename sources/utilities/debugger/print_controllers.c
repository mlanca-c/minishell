/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controllers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:26:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 13:46:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function prints the t_ctrl struct */
void	print_controllers(void)
{
	t_ctrl		*controllers;
	static char	*err[] = {"(null)", "malloc error", NULL};

	controllers = scan_controllers(NULL);
	printf("\n\n%s{ Controllers }\n", BLUE);
	printf(" [ Shell ]: %s\n", controllers->shell);
	printf(" [ Prompt ]: %s\n", controllers->prompt);
	printf(" [ Tokens ]: %p\n", &controllers->token_list);
	printf(" [ Parser ]: %p\n", &controllers->parser_tree);
	printf(" [ Env ]: %p\n", &controllers->envp);
	printf(" [ HOME ]: %s\n", scan_envp("HOME=", NULL));
	printf(" [ PWD ]: %s\n", scan_envp("PWD=", NULL));
	printf(" [ OLDPWD ]: %s\n", scan_envp("OLDPWD=", NULL));
	printf(" [ error ]: %s\n%s", err[scan_error(NULL)], RESET);
}
