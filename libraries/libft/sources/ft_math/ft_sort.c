/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:46:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/11 15:47:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_sort() function takes a integer array, and sorts it from smaller
** number in the first position to bigger number in the last position.
**
** @param	int	*array	- integer array to be sorted.
** @param	int	size	- length of the array.
*/
void	ft_sort(int *array, int size)
{
	int	position;
	int	compare;
	int	temporary;

	position = 0;
	compare = 0;
	while (position < size)
	{
		while (compare < size)
		{
			if (array[compare] >= array[position])
			{
				temporary = array[compare];
				array[compare] = array[position];
				array[position] = temporary;
			}
			compare++;
		}
		compare = 0;
		position++;
	}
}
