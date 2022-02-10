/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:49:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/01 21:20:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_EXPANSION_H
# define WORD_EXPANSION_H

/* word_expansion.c Functions */
void	word_expansion(t_cmd *command);
void	word_expansion_str(char **name);
void	word_expansion_lst(t_list *argument);

/* word_expansion related Functions */
void	tilde_expansion(void **word);
void	variable_expansion(void **word);
void	filename_expansion(void **word);
void	quote_removal(void **word);
t_list	*update_list_prefix(t_list *list, char *prefix);
t_list	*update_list_suffix(t_list *list, char *suffix);

#endif /* WORD_EXPANSION_H */
