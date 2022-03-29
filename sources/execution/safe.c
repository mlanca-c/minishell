/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:08:23 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/29 23:19:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	safe_keeping(int ret)
{
	if (ret == -1)
	{
		perror("Congratulations! You managed to crash " SHELL);
		exit_shell();
	}
	return (ret);
}
