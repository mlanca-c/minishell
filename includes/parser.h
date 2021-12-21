/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/18 19:48:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** Command Possibilities:
*/
# define COMMAND			"Command"
# define PIPELINE			"Pipeline"
# define LIST				"List"

/*
** Token Possibilities:
*/
# define WORD				1
# define ASSIGNMENT_WORD	2
# define IO_NUMBER			3
# define PIPE				4
# define LESS				5
# define GREAT				6
# define DLESS				7
# define DGREAT				8
# define AND_IF				9

/*
*/
typedef int	t_token_type;

/*
*/
typedef struct s_token
{
	char			*text;
	t_token_type	type;
}	t_token;

/*
*/
typedef struct s_parser
{
	char	*type;
	void	*command;
}	t_parser;

/*
** parser.c Function
*/
void	parser(char *line);

/*
** lexer.c Function
*/
void	*lexer(char *line);

#endif /* PARSER_H */
