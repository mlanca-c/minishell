/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:03:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 14:55:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLERS_H
# define CONTROLLERS_H

/* controllers_scanners.c Functions */
t_ctrl	*scan_controllers(char *envp[]);
char	*scan_envp(char *key, char *value);
char	**scan_path(void);
t_err_t	scan_error(void *err);
char	*scan_directory(void);

/* constrollers.c Functions */
t_dict	*controllers_get_envp(char *envp[]);

#endif /* CONTROLLERS_H */