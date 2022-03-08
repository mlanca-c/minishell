/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/03/07 23:43:15 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# define CHILD 1
# define PARENT 2

typedef struct s_command_information
{
	int		lst_size;
	int		fd[2];
	bool	has_infile;
	bool	has_outfile;
	int		status;
	int		return_value;
}	t_cmd_info;

void		execute_command_lst(t_list *cmd);
t_cmd_info	*scan_info(t_list *cmd);
void		free_info(t_cmd_info *info);
int			unlock_file(int fd, t_red *redir, int flags, mode_t mode);
int			check_infiles(t_cmd *command);
int			check_outfiles(t_cmd *command);
void		set_pipes(int **pipes, t_cmd *command, int index);
int			**init_pipes(t_cmd_info *info);
//void		set_redirs(void);
int			has_redir(t_cmd *command, int type);

#endif /*COMMANDS_H*/