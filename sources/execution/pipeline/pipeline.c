/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:46:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 23:42:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pipe_in(void);
static void	set_pipe_out(void);
static void	set_pipe_in_out(void);

// This function connects all commands via pipelines with the dup2 command.
// It redirects all fds in order for the pipe to work.
void	set_pipes(t_cmd *command)
{
	if (command->pipe == PIPE_IN)
		set_pipe_in();
	else if (command->pipe == PIPE_OUT)
		set_pipe_out();
	else if (command->pipe == PIPE_IN_OUT)
		set_pipe_in_out();
}

static void	set_pipe_in(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// if possible close this. This is never going to happen.
	// if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
	// {
		// printf("Close not suppose to happen but it did.\n");
		// safe_keeping(close(info->io->curr_in_fd));
	// }
	safe_keeping(pipe(info->pipe_fd));
	safe_keeping(dup2(info->pipe_fd[READ], STDIN_FILENO));
	info->io->curr_in_fd = info->pipe_fd[READ];
}

static void	set_pipe_out(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
	// {
		// printf("Close not suppose to happen but it did.\n");
		// safe_keeping(close(info->io->curr_out_fd));
	// }
	safe_keeping(dup2(info->pipe_fd[WRITE], STDOUT_FILENO));
	info->io->curr_out_fd = info->pipe_fd[WRITE];
}

static void	set_pipe_in_out(void)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
	// {
		// printf("Close not suppose to happen but it did.\n");
		// safe_keeping(close(info->io->curr_in_fd));
	// }
	// if (info->io->curr_out_fd != STDOUT_FILENO && info->io->curr_out_fd != -1)
	// {
		// printf("Close not suppose to happen but it did.\n");
		// safe_keeping(close(info->io->curr_out_fd));
	// }
	safe_keeping(dup2(info->pipe_fd[READ], STDIN_FILENO));
	info->io->curr_in_fd = info->pipe_fd[READ];
	safe_keeping(pipe(info->pipe_fd));
	safe_keeping(dup2(info->pipe_fd[WRITE], STDOUT_FILENO));
	info->io->curr_out_fd = info->pipe_fd[WRITE];
}
