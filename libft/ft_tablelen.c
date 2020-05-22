/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablelen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:11:16 by md4               #+#    #+#             */
/*   Updated: 2020/05/22 19:27:44 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function: ft_tablelen
** Parameter(s):
**		char **table: table of str
** Description:
**		Calculate the lenght of the table (how many string it contains).
** Return:
**		len: the lenght of the table.
**		-1: if the table has no lenght.
*/

int			ft_tablelen(char **table)
{
	int		i;

	i = 0;
	if (table == NULL)
		return (-1);
	while (table[i] != NULL)
		i++;
	return (i);
}
