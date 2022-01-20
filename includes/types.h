/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/20 19:29:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* enumeration of all possible errors */
typedef enum e_error_type
{
	null = 0
}	t_err_t;

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
	R_PAR = 12,
	NEW_LINE = 13
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

/* structure representing a Simple Command */
typedef struct s_command
{
	char	*name;
	t_list	*suffix;
	t_list	*prefix;
}	t_cmd;

/* structure representing a Simple Command */
typedef struct s_ast_node
{
	t_cmd_t	type;
	t_cmd	*cmd;
}	t_node;

/* main structure */
typedef struct s_controllers
{
	char	*shell;
	char	*prompt;

	t_list	*token_list;
	t_ast	*parser_tree;

	t_list	*envp;
	char	**path;
	char	*home;
	char	*directory;

	t_err_t	error;
	bool	debugger;
}	t_ctrl;

#endif /* TYPES_H */
