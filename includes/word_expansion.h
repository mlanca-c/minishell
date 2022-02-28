/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:49:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 18:06:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_EXPANSION_H
# define WORD_EXPANSION_H

/* word_expansion.c Functions */
void	word_expansion(t_cmd *command);

/* word_expansion related Functions */
char	*tilde_expansion(char *str);
char	*variable_expansion(char *str);
char	*filename_expansion(char *str);
char	*quote_removal(char *str);

#endif /* WORD_EXPANSION_H */
