/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/06 13:56:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* enumeration of all possible errors */
// typedef enum e_error_type
// {
// 	NULL
// }	t_error_t;

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
	AND_IF = 8,
	OR_IF = 9,
}	t_token_t;

/* enumeration of all possible commands */
typedef enum e_command_type
{
	Simple_Command = 0,
	Pipeline = 1,
	List = 2
}	t_cmd_t;

/* structure representing a token */
typedef struct s_token
{
	t_token_t	type;
	char		*text;
}	t_token;

/* structure representing a simple commands */
typedef struct s_command
{
	t_list	*suffix;		// can be assignments, what else ?!
	char	*name;
	t_list	*prefix;
}	t_cmd;

/*
typedef struct s_list_commad
{
	void	*right;
	void	*left;
}	t_lst;
*/

/* structure representing all parsing */
typedef struct s_parser
{
	t_cmd_t	type;
	void	*cmd;
}	t_parse;
/* If type is Simple_Command, then void *cmd ==>> t_list<t_cmd> *cmd of size 1. */
/* If type is Pipeline, then void *cmd ==>> t_list<t_cmd> *cmd of size nu_pipes + 1. */
/* 		If type is List, then void *cmd ==>> t_list_cmd *list that has left and right. */
/* 		Left and right type is either t_list_cmd more list or t_list for Pipeline of Simple_Command. */

/* main structure */
typedef struct s_controllers
{
	char	*shell;
	char	*prompt;
	t_list	*token_list;
	t_parse	*parser;
	char	**path;
	char	*home;
}	t_ctrl;

#endif /* TYPES_H */
