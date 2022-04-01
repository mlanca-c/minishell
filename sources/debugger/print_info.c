/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:12:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 22:52:22 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_io(void);

void	print_info(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	fprintf(stderr, "%s{ Info }:\n", RED);
	fprintf(stderr, "  [ HERE_DOC FILE ]: %s\n", info->heredoc_file);
	fprintf(stderr, "  [ SIZE ]: %d\n", info->lst_size);
	fprintf(stderr, "  [ PIPE_FD ]: [%ls, %ls]\n", info->pipe_fd[0], info->pipe_fd[1]);
	fprintf(stderr, "  [ IO ]:\n");
	print_io();
	fprintf(stderr, "  [ STATUS ]: %d\n%s\n", info->status, RESET);
}

static void	print_io(void)
{
	t_io	*io;

	io = scan_info(NULL)->io;
	fprintf(stderr, "    [ CURRENT_FD ][IN]: %d\n", io->curr_in_fd);
	fprintf(stderr, "    [ CURRENT_FD ][OUT]: %d\n", io->curr_out_fd);
	fprintf(stderr, "    [ SAVED ][IN]: %d\n", io->saved_stdin);
	fprintf(stderr, "    [ SAVED ][OUT]: %d\n", io->saved_stdout);
	fprintf(stderr, "    [ RESET ? ][IN]: %d\n", io->reset_in);
	fprintf(stderr, "    [ RESET ? ][OUT]: %d\n", io->reset_out);
	fprintf(stderr, "    [ SAFE ][IN]: %d\n", io->in_safe);
	fprintf(stderr, "    [ SAFE ][OUT]: %d\n", io->out_safe);
}
