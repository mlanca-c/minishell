/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/28 16:06:55 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct s_command_information
{
	int	lst_size;
	int	**pipes;
	int	return_value;
}	t_cmd_info;

void		execute_command_lst(t_list *cmd);
t_cmd_info	*scan_info(t_list *cmd);
void		free_info(t_cmd_info *info);
int			unlock_file(int fd, t_red *redir, int flags, mode_t mode);
int			open_files(t_cmd *command);
void		set_pipes(int **pipes, t_cmd *command, int index);
int			**init_pipes(t_cmd_info *info);

#endif /*COMMANDS_H*/