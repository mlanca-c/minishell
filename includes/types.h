/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:19:51 by mlanca-c         ###   ########.fr       */
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
	List = 2,
	Here_Document = 3
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
	char	*cmd_name;
	t_list	*cmd_arguments;
}	t_cmd;

/* structure representing all parsing */
typedef struct s_parser
{
	t_cmd_t	type;
	void	*command;
}	t_parse;

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
