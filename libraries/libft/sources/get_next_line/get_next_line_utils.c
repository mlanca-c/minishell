/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:43:31 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/12 12:06:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function sees what the read() from get_next_line() returned. If it
** returned 0 that means that there is no more data to read from the fd. Else
** the EOF hasn't been reached and the function returns 1.
**
** @param int reader		the return of the read function.
**
** @return
** 		 1	  if EOF wasn't reached.
** 		 0	  if it has reached the EOF.
*/
int	return_value(int reader)
{
	if (reader == 0)
		return (0);
	return (1);
}

/*
** This function checks if the param str contains '\n'. 
** @param char	*saved		string with that might or might not have a '\n'.
**
** @return
** 	1	if saved has a '\n'.
** 	0	if saved doesn't have a '\n'.
*/
int	has_new_line(char *saved)
{
	int	i;

	if (!saved)
		return (0);
	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
** This function creates a char * called tab, that allocates the necessary
** amount of memory to be able to contain saved and buf together.
**
** @param	char *saved		first string of characters being copied to tab.
** @param	char *buf		second string of characters being copied to tab.
**
** @returns		both strings joined in one string - new.
*/
char	*join_saved_buf(char *saved, char *buf)
{
	char	*new;

	if (!saved && !buf)
		return (NULL);
	if (!saved)
		return (ft_strdup(buf));
	new = ft_strjoin(saved, buf);
	free(saved);
	return (new);
}
