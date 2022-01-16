/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 17:58:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* enumeration of all possible errors */

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
	Here_Document = 3
	/*And_List = 4,
	Or_List = 5, */
}	t_cmd_t;

/* structure representing a token */
typedef struct s_token
{
	t_token_t	type;
	char		*text;
}	t_token;

/*
enumeration of all possible redirection token types
typedef enum e_redirection_type
{
	LESS = 1,
	GREAT = 2,
	DLESS = 3,
	DGREAT = 4
}	t_red_t;

structure representing a redirection
typedef struct s_redirection
{
	t_red_t	type;
	char	*io_file;
}	t_red;
*/

/* structure representing an assignment */
typedef struct s_assignment
{
	char	*name;
	char	*value;
}	t_assign;

typedef struct s_command
{
	char	*name;
	t_list	*arguments;
	/* t_red	*redirection */
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
