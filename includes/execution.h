/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:15:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 20:57:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/* Pipes */
# define READ 0
# define WRITE 1

/* Files */
# define IN 0
# define OUT 1

/* Exit status code */
# define SUCCESS 			0
# define FAILURE			1
# define BUILTIN_FAILURE	2
# define COMMAND_FAILURE	126
# define COMMAND_NOT_FOUND	127
# define SGN 				128

/* Position of a command in the pipeline */
# define NO_PIPE 0
# define PIPE_IN 1
# define PIPE_OUT 2
# define PIPE_IN_OUT 3

/* execution.c Functions */
void	execution(t_dlist *lst);

/* info.c Functions */
void	init_info(t_dlist *lst, int std_fd[2]);
void	close_info_fd(t_dlist *lst, int std_fd[2]);

/* file_descriptor.c Function */
void	file_descriptors(t_dlist *lst, int std_fd[2]);

/* utils.c Functions */
int		safe_keeping(int ret);

#endif /* EXECUTION_H */
