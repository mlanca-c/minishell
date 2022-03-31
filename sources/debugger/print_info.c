/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:12:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 19:38:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_info(t_cmd *command)
{
	t_info	*info;
	static char	*type[] = {"NO_PIPE", "PIPE_IN", "PIPE_OUT", "PIPE_IN_OUT",
		NULL};

	info = command->info;
	if (command->name)
		fprintf(stderr, "%s\n", command->name);
	fprintf(stderr, "%s{ Info }:\n", CYAN);
	fprintf(stderr, "  [ PID ]: %d\n", info->pid);
	fprintf(stderr, "  [ PIPE ]: [%d, %d]\tSTDIN(0);STDOUT(1)\n", info->cur_fd[IN], info->cur_fd[OUT]);
	fprintf(stderr, "  [ TYPE ]: %s\n", type[info->type]);
	fprintf(stderr, "  [ STATUS ]: %d\n%s\n", info->status, RESET);
}
