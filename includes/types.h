/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/09 21:06:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* bash like promp Macros */
# define SHELL		"crash"
# define PROMPT		"crash-1.0$ "

/* oh-my-zsh like promp Macros */
# define ZSH_SHELL	"oh-my-crash"
# define ZSH_PROMPT	"➜ "

/* enumeration of all possible errors */
typedef enum e_error_type
{
	NO_ERROR,
	MALLOC,
	DUP,
	CLOSE,
	OTHER
}	t_err_t;

/* enumeration of all possible tokens */
typedef enum e_token_type
{
	WORD = 0,
	PIPE = 1,
	LESS = 2,
	GREAT = 3,
	DLESS = 4,
	DGREAT = 5,
	AND_IF = 6,
	OR_IF = 7,
	L_PAR = 8,
	R_PAR = 9,
	NEW_LINE = 10
}	t_token_t;

/* enumeration of all possible commands */
typedef enum e_command_type
{
	Simple_Command = 0,
	Pipeline = 1,
	And_List = 2,
	Or_List = 3
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
	t_list	*suffix;
	char	*name;
	t_list	*prefix;
	t_list	*redirection;
}	t_cmd;

/* structure representing a parser_tree node */
typedef struct s_ast_node
{
	t_cmd_t	type;
	t_cmd	*cmd;
}	t_node;

/* structure representing a node of a redirections list in t_cmd */
typedef struct s_redirection
{
	t_token_t	io_type;
	char		*io_file;
}	t_red;

/* main structure */
typedef struct s_controllers
{
	char	*shell;
	char	*prompt;

	t_list	*token_list;
	t_ast	*parser_tree;
	t_dict	*envp;

	t_err_t	error;
	int		return_value;
	bool	debugger;
}	t_ctrl;

#endif /* TYPES_H */
