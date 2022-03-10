/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 11:27:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# define CHILD 1
# define PARENT 2

# define READ 0
# define WRITE 1

typedef struct s_command_information
{
	int		lst_size;
	int		fd[2];
	bool	has_infile;
	bool	has_outfile;
	int		status;
	int		return_value;
}	t_cmd_info;

/* info Functions */
t_cmd_info	*scan_info(t_list *cmd);

/* exec_command_lst Functions */
void	execute_command_lst(t_list *cmd);
void	exec_cmd(t_list *cmd, t_cmd_info *info, int index);
//void	exec_builtin(t_cmd *cmd);
void	exec_program(t_cmd *command);

/* exec_command_lst_utils Functions */
int		is_builtin(t_cmd *cmd);

/* set_redirs Functions */
int		check_infiles(t_cmd *command);
int		check_outfiles(t_cmd *command);
int		unlock_file(int fd, t_red *redir, int flags, mode_t mode);

/* do_pipes Functions */
void	set_pipes(int index);

/* processes Functions */
void	exec_child(t_cmd *cmd);
void	exec_parent(void);

/* processes_utils Functions */
int		has_absolute_path(t_cmd *cmd);
int		has_relative_path(t_cmd *cmd);
char	*get_path(t_cmd *cmd);


#endif /*COMMANDS_H*/