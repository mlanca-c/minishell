/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:07 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 16:44:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*
*/
typedef enum e_token_type
{
	WORD = 1,
	ASSIGNMENT_WORD = 2,
	IO_NUMBER = 3,
	PIPE = 4,
	LESS = 5,
	GREAT = 6,
	DLESS = 7,
	DGREAT = 8,
	AND_IF = 9,
	OR_IF = 10,
}	t_token_type;

/*
*/
typedef struct s_token
{
	t_token_type	type;
	char			*text;
}	t_token;

/*
*/
typedef enum e_command_type
{
	Simple_Command = 11,
	Pipeline = 12,
	Here_Document = 13,
	List = 14
}	t_command_type;

/*
*/
typedef struct s_simple_command
{
	t_list	*prefix;
	t_token	command;
	t_list	*suffix;
}	t_simple_command;

/*
*/
typedef struct s_pipeline
{
	t_list	**simple_command;
}	t_pipeline;

/*
*/
typedef struct s_lst
{
	void	*left;
	void	*right;
}	t_lst;

/*
*/
typedef struct s_parser
{
	t_command_type	command_type;
	void			*command;
}	t_parser;

#endif /* TYPES_H */
