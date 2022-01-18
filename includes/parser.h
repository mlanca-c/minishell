/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/18 00:55:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define GET	0
# define NEXT	1
# define UPDATE	2
# define INIT	3

/* parser.c Function */
t_list	*lexical_analyser(char *line);
t_ast	*parser(void);

/* parse_paren.c Function */
t_ast	*parse_paren(void);

/* parse_list.c Function */
t_ast	*parse_list(void);
t_ast	*new_or_list(t_ast *a, t_ast *b);
t_ast	*new_and_list(t_ast *a, t_ast *b);

/* parse_pipe.c Function */
t_ast	*parse_pipe(void);
t_ast	*new_pipe(t_ast *a, t_ast *b);

/* parse_token.c Function */
t_ast	*parse_token(void);

/* token.c Functions */
t_token	*scan_token(int status);
void	free_token(void *token);

/* token_recognition.c Functions */
int			token_recognition(t_list **token_list, char *line);
t_token_t	token_assignment(char *text);
t_token		*token_update(char *text, int end);
int			token_quotes(char *line);
void		token_definition(t_list *token_list);
#endif /* PARSER_H */
