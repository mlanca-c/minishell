/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/12 16:18:06 by josantos         ###   ########.fr       */
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
	int		curr_out_fd;
	int		curr_in_fd;
	int		saved_stdin;
	int		reset_in;
	bool	in_safe;
	int		saved_stdout;
	int		reset_out;
	bool	out_safe;
}	t_io;
typedef struct s_command_information
{
	char	*heredoc_file;
	int		lst_size;
	int		pipe_fd[2];
	t_io	*io;
	int		return_value;
	int		status;
}	t_cmd_info;

/* info Functions *****************************************/
t_cmd_info	*scan_info(t_list *cmd);
t_io		*init_io(void);
void		free_info(t_cmd_info *info);

/* exec_command_lst Functions *****************************/
void		execute_command_lst(t_list *cmd);
int			implement_cmd(t_list *cmd, t_cmd_info *info, int index);
//void		exec_builtin(t_cmd *cmd);
void		exec_program(t_cmd *command);

/* exec_command_lst_utils Functions ***********************/
int			is_builtin(t_cmd *cmd);
void		t_pipe_init(t_cmd *command, int index);

/* file_descriptors Functions******************************/
int			do_dup(int fd);
int			do_dup2(int old_fd, int new_fd);

/* heredoc Functions **************************************/
int			setup_heredoc(t_red *redir);

/*ios Functions********************************************/
	/*reset_ios.c */
int			reset_ios(bool reset_in, bool reset_out);
int			reset_is(t_cmd_info *info);
int			reset_os(t_cmd_info *info);

	/*set_ios.c */
int			set_ios(t_cmd *command);
int			check_save_ios(t_cmd *command);
int			save_ios(int type);

/* redirs Functions ***************************************/
	/* change_fd.c */
int			change_in(t_red	*redir, int old_fd);
int			change_out(t_red *redir, int old_fd);
int			get_fd(t_red *redir, t_cmd_info *info);

	/* do_pipes.c */
int			set_pipes(t_cmd *command);
int			set_pipe_in(void);
int			set_pipe_out(void);
int			set_pipe_in_out(void);

	/*do_pipes_utils.c */
int			do_pipe(int fd[2]);
int			do_close(int fd);

	/* set_redirs.c */
int			do_redirs(t_cmd *command);
int			infile_process(t_red *redir);
int			outfile_process(t_red *redir);

/* processes Functions************************************/
void		exec_child(t_cmd *cmd);
void		exec_parent(void);

/* processes_utils Functions******************************/
int			has_path(t_cmd *cmd);
char		*get_path(t_cmd *cmd);
char		*check_stat(char **paths, t_cmd *cmd);
char		**get_array(t_cmd *cmd);
void		handle_error(t_cmd *cmd);

#endif /*COMMANDS_H*/