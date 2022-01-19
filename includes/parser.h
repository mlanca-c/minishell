/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 20:26:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define GET	0
# define NEXT	1
# define CLEAR	2

/* parser.c Function */
t_list		*lexical_analyser(char *line);
t_ast		*parser(void);
void		free_parser(t_ast *parser);

/* token.c Functions */
t_token		*scan_token(int status);
void		free_token(void *token);

/* parse Functions */
t_ast		*parse_pipe(void);
t_ast		*parse_command(void);

/* command Functions */
t_list		*command_prefix(void);
char		*command_name(void);
t_list		*command_suffix(void);

/* token_recognition.c Functions */
int			token_recognition(t_list **token_list, char *line);
t_token_t	token_assignment(char *text);
t_token		*token_update(char *text, int end);
int			token_quotes(char *line);
void		token_definition(t_list *token_list);

#endif /* PARSER_H */
