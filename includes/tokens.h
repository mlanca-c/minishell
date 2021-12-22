/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:43:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/22 16:43:54 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

/*
** tokens.c Functions
*/
int				token_recognition(t_list **token_list, char *line);
int				token_quotes(char *line);
t_token			*token_update(char *text, int end);
t_token_type	token_assignment(char *text);
void			token_free(t_list *token_list);

// TO DELETE
void	print_token(t_list *token_list);

#endif /* TOKENS_H */
