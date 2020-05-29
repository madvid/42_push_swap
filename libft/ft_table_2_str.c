/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_2_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:29:04 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 02:40:01 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function: ft_fill_str_w_tablestr
** Parameters:
**		char *str:
**		char **table:
** Description:
**	Copy the lines of table in str.
** Return:
**		None
*/

static void	ft_fill_str_w_tablestr(char *str, char **table)
{
	size_t	l;
	size_t	c;
	size_t	i;

	i = 0;
	if (table == NULL || str == NULL)
		return ;
	l = 0;
	while (table[l])
	{
		c = 0;
		while (table[l][c] != '\0')
		{
			str[i] = table[l][c];
			i++;
			c++;
		}
		l++;
	}
}

/*
** Function: ft_table_2_str
** Parameters:
**      char **table: table to convert into str.
** Description:
**  Function allocate a str and copy each lines of the table in the str.
** Return:
**      NULL:
**      char *str: a copy of each lines of table in a single line.
*/

char		*ft_table_2_str(char **table)
{
	size_t	line;
	size_t	n_char;
	char	*str;

	line = ft_tablelen(table);
	if (table == NULL && line == 0)
		return (NULL);
	n_char = ft_table_nb_char(table);
	//if ((str = ft_strnew(n_char + line)) == NULL)
	if ((str = ft_strnew(n_char)) == NULL)
		return (NULL);
	ft_fill_str_w_tablestr(str, table);
	return (str);
}
