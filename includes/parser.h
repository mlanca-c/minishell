/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:35:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* parser.c Function */
t_list		*lexical_analyser(char *line);
t_parse		*grammatical_analyser(t_list *token_list);

/* tokens.c Functions */
int			token_recognition(t_list **token_list, char *line);
int			token_quotes(char *line);
t_token		*token_update(char *text, int end);
t_token_t	token_assignment(char *text);

#endif /* PARSER_H */
