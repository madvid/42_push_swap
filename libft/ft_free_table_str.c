/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_table_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:24:13 by md4               #+#    #+#             */
/*   Updated: 2020/05/19 16:45:02 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Function: ft_free_table_str
** Parameters:
**		char** table: table to free.
** Description:
**		Free memory allocated for the table.
** Return:
**		None.
*/

void	ft_free_table_str(char **table)
{
	size_t	i;

	i = 0;
	if (table == NULL)
		return ;
	while (table[i] != NULL)
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	table = NULL;
}
