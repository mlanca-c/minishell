/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 15:28:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define GET	0
# define NEXT	1
# define CLEAR	2

/* parser.c Function */
t_dlist		*lexer(char *line);
t_ast		*parser(void);

/* parser Functions */
t_ast		*parse_list(void);
t_ast		*parse_pipe(void);
t_ast		*parse_command(void);

/* command.c Functions */
t_cmd		*command(void);

/* token Functions */
int			token_recognition(t_dlist **token_list, char *line);
void		token_definition(t_dlist *token_list);
t_token		*scan_token(int status);

/* resrap.c Functions */
void	resrap(void);
#endif /* PARSER_H */
