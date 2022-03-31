/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/31 15:33:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

/* Processes */
# define CHILD 1
# define PARENT 2

/* Pipes */
# define READ 0
# define WRITE 1

/* Files */
# define IN 1
# define OUT 2

# define NO_PIPE 0
# define PIPE_IN 1
# define PIPE_OUT 2
# define PIPE_IN_OUT 3

typedef struct s_input_output
{
	int		curr_in_fd;
	int		curr_out_fd;
	int		saved_stdin;
	int		saved_stdout;
	int		reset_in;
	int		reset_out;
	bool	in_safe;
	bool	out_safe;
}	t_io;
typedef struct s_command_information
{
	char	*heredoc_file;
	int		lst_size;
	int		pipe_fd[2];
	t_io	*io;
	t_stack	*pid_lst;
	int		status;
}	t_cmd_info;

t_cmd_info	*scan_info(t_dlist *command);
void		free_info(t_cmd_info *info);
void		init_pipe(t_cmd *command, int index);
int			setup_heredoc(t_red *redir);
void		reset_ios(bool reset_in, bool reset_out);
int			set_ios(t_cmd *command);
int			check_save_ios(t_cmd *command);
void		save_ios(int type);
int			change_in(t_red	*redir, int old_fd);
int			change_out(t_red *redir, int old_fd);
void		set_pipes(t_cmd *command);
int			safe_keeping(int ret);
int			do_redirs(t_cmd *command);
int			has_path(t_cmd *cmd);
char		*check_stat(char **paths, t_cmd *cmd);
char		**get_array(t_cmd *cmd);
void		handle_error(t_cmd *cmd);

#endif /* COMMANDS_H */
