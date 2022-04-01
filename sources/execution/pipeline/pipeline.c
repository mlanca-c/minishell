/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:46:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 23:35:35 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_pipe_in(int i);
static void	set_pipe_out(void);
static int	set_pipe_in_out(int i);


void	init_pipe(t_cmd *command, int index)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (index == 1 && info->lst_size > 1)
		command->pipe = PIPE_OUT;
	else if (index == 1 && info->lst_size == 1)
		command->pipe = NO_PIPE;
	else if (index > 0 && index < info->lst_size)
		command->pipe = PIPE_IN_OUT;
	else if (index > 0 && index == info->lst_size)
		command->pipe = PIPE_IN;
	else
		printf("Congratulations! You managed to crash " SHELL "\n");
}

// This function connects all commands via pipelines with the dup2 command.
// It redirects all fds in order for the pipe to work.
void	set_pipes(t_cmd *command)
{
	static int	i = -1;
	t_cmd_info	*info;

	info = scan_info(NULL);
	if (i < 0)
		i = (int)info->lst_size - 2;
	if (command->pipe == PIPE_IN)
		i = set_pipe_in(i);
	else if (command->pipe == PIPE_OUT)
		set_pipe_out();
	else if (command->pipe == PIPE_IN_OUT)
		i = set_pipe_in_out(i);
}

static int	set_pipe_in(int i)
{
	t_cmd_info	*info;

	info = scan_info(NULL);
	// if possible close this. This is never going to happen.
	// if (info->io->curr_in_fd != STDIN_FILENO && info->io->curr_in_fd != -1)
	// {
	// 	printf("Close not suppose to happen but it did.\n");
	// 	safe_keeping(close(info->io->curr_in_fd));
	// }
	//safe_keeping(pipe(info->pipe_fd[i]));
	safe_keeping(dup2(info->pipe_fd[i][READ], STDIN_FILENO));
	info->io->curr_in_fd = info->pipe_fd[i][READ];
	return (i--);
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
	safe_keeping(dup2(info->pipe_fd[0][WRITE], STDOUT_FILENO));
	info->io->curr_out_fd = info->pipe_fd[0][WRITE];
}

static int	set_pipe_in_out(int i)
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
	safe_keeping(dup2(info->pipe_fd[i + 1][WRITE], STDOUT_FILENO));
	info->io->curr_out_fd = info->pipe_fd[i + 1][WRITE];
	//safe_keeping(pipe(info->pipe_fd[i]));
	safe_keeping(dup2(info->pipe_fd[i][READ], STDIN_FILENO));
	info->io->curr_in_fd = info->pipe_fd[i][READ];
	return (i--);
}

void	close_pipes(void)
{
	int			i;
	int			nb_pipes;
	t_cmd_info	*info;

	i = 0;
	info = scan_info(NULL);
	nb_pipes = info->lst_size - 1;
	while (i < nb_pipes)
	{
		if (info->pipe_fd[i][0] != -1)
		close(info->pipe_fd[i][0]);
		close(info->pipe_fd[i][1]);
		i++;
	}
}
