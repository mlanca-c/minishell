/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_instructions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/10 00:36:20 by josantos         ###   ########.fr       */
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

/* std_io info */
typedef struct s_std_io
{
	int		std_in;
	int		std_out;
	int		curr_in;
	int		curr_out;
	bool	in_saved;
	bool	out_saved;
}	t_std_io;

/* Redirs */
typedef struct s_redirs
{
	bool	in;
	bool	out;
}	t_redirs;

typedef struct s_command_information
{
	int		lst_size;
	int		fd[2];
	int		status;
}	t_cmd_info;

/* info Functions */
t_cmd_info	*scan_info(t_list *cmd);

/* t_std_io Functions */
t_std_io	*scan_std_io(char *placeholder);




/*
void		execute_command_lst(t_list *cmd);
t_cmd_info	*scan_info(t_list *cmd);
void		free_info(t_cmd_info *info);
int			unlock_file(int fd, t_red *redir, int flags, mode_t mode);
int			check_infiles(t_cmd *command);
int			check_outfiles(t_cmd *command);
void		set_pipes(int index);
int			**init_pipes(t_cmd_info *info);
//void		set_redirs(void);
int			has_redir(t_cmd *command, int type);
*/

#endif /*COMMANDS_H*/