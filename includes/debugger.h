/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:04:21 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/25 10:17:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGER_H
# define DEBUGGER_H

/* debugger Functions */
void	print_controllers(void);
void	print_tokens(void);
void	print_parser(void);

/* debugger command Functions */
void	print_commands(t_ast *parser);
void	print_command_lst(t_list *lst);
void	print_command_red(t_list *lst);

/* redirection Function */
void	print_redirections(t_cmd *command);

#endif /* DEBUGGER_H */
