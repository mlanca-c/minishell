/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/16 18:08:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* parser.c Function */
t_list		*lexical_analyser(char *line);
t_ast		*grammatical_analyser(t_list *token_list);

/* command.c Functions*/
t_cmd		*get_command(t_list **token_list);
void		command_add_parser(t_ast *parser, t_cmd *node);

/* separator.c Functions */
bool		is_token_separator(t_token_t type);
t_cmd_t		get_separator(t_list **token_list);
void		separator_add_parser(t_ast *parser, t_cmd_t node);

/* assignment.c Functions*/
t_assign	*get_assignment(t_list **token_list);
void		assignment_add_parser(t_ast *parser, t_assign *node);

/* tokens.c Functions */
int			token_recognition(t_list **token_list, char *line);
t_token_t	token_assignment(char *text);
t_token		*token_update(char *text, int end);
int			token_quotes(char *line);
void		token_files(t_list *token_list);

#endif /* PARSER_H */
