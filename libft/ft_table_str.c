/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:08:27 by md4               #+#    #+#             */
/*   Updated: 2020/05/19 17:14:59 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Function: ft_table_str
** Parameters:
**		size_t lenght: number of rows of the table (NULL terminate excluded).
**		size_t width: width of the strings (NULL end excluded).
** Description:
**		Allocate a string table of (lenght + 1) (NULL terminated included) and
**		of (width + 1) (NULL terminaison included).
** Return:
**		NULL, if memory allocation issue.
**		char**, table of string of dimension [total+1,width+1]
*/

char	**ft_table_str(size_t lenght, size_t width)
{
	char		**str;
	size_t		i;

	i = 0;
	if (lenght == 0 || width == 0)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (lenght + 1))))
		return (NULL);
	str[lenght] = NULL;
	while (i < lenght)
	{
		if (!(str[i] = (char*)malloc(sizeof(char) * (width + 1))))
		{
			while (i > 0)
			{
				free(str[i]);
				i--;
			}
			free(str);
			return (NULL);
		}
		ft_strcpy(str[i], "000\n");
		i++;
	}
	return (str);
}
