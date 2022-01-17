/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/17 17:49:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* enumeration of all possible errors
typedef enum e_error_type
{
	Malloc_Controllers = 0,
	Malloc_Token = 1,
	Malloc_Token_List = 2
}	t_err_t;*/

/* enumeration of all possible tokens */
typedef enum e_token_type
{
	WORD = 0,
	ASSIGNMENT_WORD = 1,
	IO_NUMBER = 2,
	PIPE = 3,
	LESS = 4,
	GREAT = 5,
	DLESS = 6,
	DGREAT = 7,
	IO_FILE = 8,
	AND_IF = 9,
	OR_IF = 10,
	L_PAR = 11,
	R_PAR = 11
}	t_token_t;

/* enumeration of all possible commands */
typedef enum e_command_type
{
	Simple_Command = 0,
	Pipeline = 1,
	Assignment_Word = 2,
	Here_Document = 3,
	And_List = 4,
	Or_List = 5
}	t_cmd_t;

/* structure representing a token */
typedef struct s_token
{
	t_token_t	type;
	char		*text;
}	t_token;

/* structure representing a redirection */
typedef struct s_redirection
{
	t_token_t	type;
	char		*io_file;
}	t_red;

/* structure representing a Simple Command */
typedef struct s_command
{
	char	*name;
	t_list	*arguments;
	t_list	*redirections;
}	t_cmd;

/* main structure */
typedef struct s_controllers
{
	char	*shell;
	char	*prompt;
	t_list	*token_list;
	t_ast	*parser;
	char	**path;
	char	*home;
}	t_ctrl;

#endif /* TYPES_H */
