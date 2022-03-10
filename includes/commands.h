/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 15:17:28 by josantos         ###   ########.fr       */
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

typedef struct s_original_file_descriptors
{
	int		curr_out_fd;
	int		curr_in_fd;
	int		saved_stdin;
	int		saved_stdout;
}	t_og_fd;
typedef struct s_command_information
{
	int		lst_size;
	int		pipe_fd[2];
	t_og_fd	*og_fd;
	bool	has_infile;
	bool	has_outfile;
	int		status;
	int		return_value;
}	t_cmd_info;

/* info Functions */
t_cmd_info	*scan_info(t_list *cmd);
t_og_fd		*init_og_fd(void);
void		free_info(t_cmd_info *info);

/* exec_command_lst Functions */
void		execute_command_lst(t_list *cmd);
int			exec_cmd(t_list *cmd, t_cmd_info *info, int index);
//void		exec_builtin(t_cmd *cmd);
void		exec_program(t_cmd *command);

/* exec_command_lst_utils Functions */
int			is_builtin(t_cmd *cmd);

/* file_descriptors Functions */
int			do_dup(int fd);


/* set_redirs Functions */
int			check_infiles(t_cmd *command);
int			check_outfiles(t_cmd *command);
int			check_dup(int fd, int type);
int			unlock_file(int fd, t_red *redir, int flags, mode_t mode);

/* do_pipes Functions */
void		set_pipes(int index);

/* processes Functions */
void		exec_child(t_cmd *cmd);
void		exec_parent(void);

/* processes_utils Functions */
int			has_path(t_cmd *cmd);
char		*get_path(t_cmd *cmd);
char		*check_stat(char **paths, t_cmd *cmd);
char		**get_array(t_cmd *cmd);
void		handle_error(t_cmd *cmd);

#endif /*COMMANDS_H*/