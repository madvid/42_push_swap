/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:47:36 by md4               #+#    #+#             */
/*   Updated: 2020/05/20 17:31:55 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
** Function: ft_check_full
** Parameters:
**		char **table:
**		char *motif:
** Description:
**	Compare all the elements of table with motif
** Return:
**	1: if all elements of table match motif
**	1: else if table or motif is NULL
**	0: otherwise.
*/

int		ft_check_full(char **table, char *motif)
{
	size_t		i;

	i = 0;
	if (table == NULL || motif == NULL)
		return (1);
	while (table[i] != NULL)
	{
		if (ft_strcmp(table[i], motif) != 0)
			return (0);
		i++;
	}
	return (1);
}
