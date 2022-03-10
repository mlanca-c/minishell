/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:23:50 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 03:09:38 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXEC_H
# define COMMAND_EXEC_H

/* execution_cmd_lst Functions*/
void	execute_command_lst(t_list *cmd);
int		exec_cmd(t_list *cmd);
int		cmd_execution(t_cmd *command);
int		exec_program(t_cmd *command);

/* handle_og_fds Functions */
int		save_origin_fds(void);
void	reset_origin_fd(bool has_redirs_out, bool has_redirs_in);
void	reset_origin_in_fd(void);
void	reset_origin_out_fd(void);

/* handle_og_fds_utils Functions */
void	set_curr_in_fd(t_std_io *std_io, int in_fd);
void	set_curr_out_fd(t_std_io *std_io, int out_fd);
void	save_std_in(void);
void	save_std_out(void);

/* set_redirs Functions */
int		handle_redirs(t_cmd *cmd);
int		check_heredoc(t_red *redirs, t_redirs *has_redir);
int		check_redir_files(t_red *redirs, t_redirs *has_redirs);
int		check_redir_pipes(t_red *redirs, t_redirs *has_redirs);



/* set_dups Functions */
int		set_dup(int old_fd);
int		set_dup2(int og_fd, int copy_fd);

/* set_pipe Functions */
int		set_pipe(int fd[2]);

/* do_heredoc Functions */
int		do_heredoc(t_red *redirs);

/* do_redir Functions */
int		do_redir(t_red *redirs);
int		set_redir_out(t_red *redirs);
int		set_redir_in(t_red *redirs);
int		set_redir_pipe(void);

/* unlock_file Functions */
int		unlock_file(char *filename, int flags, mode_t mode);



/* processes_functions */
int		exec_child(t_cmd *cmd);
int		exec_parent(pid_t pid);




/* command_execution Functions 
int		is_builtin(t_cmd *cmd);
void	exec_builtin(t_cmd *cmd);
void	exec_program(t_cmd *cmd);
void	close_pipes(t_cmd_info *info);*/
//void	exec_child(t_cmd *cmd);
int		has_absolute_path(t_cmd *cmd);
int		has_relative_path(t_cmd *cmd);




#endif