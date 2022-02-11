/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:24:02 by josantos          #+#    #+#             */
/*   Updated: 2022/02/11 17:38:33 by josantos         ###   ########.fr       */
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

void	execute_command_lst(t_cmd *cmd);

#endif /*COMMANDS_H*/