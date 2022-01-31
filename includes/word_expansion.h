/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:49:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/31 16:17:11 by mlanca-c         ###   ########.fr       */
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

#endif /* WORD_EXPANSION_H */
