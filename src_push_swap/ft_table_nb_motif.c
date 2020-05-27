/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_nb_motif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:03:34 by md4               #+#    #+#             */
/*   Updated: 2020/05/26 15:31:42 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
** Function: ft_table_motif
** Parameters:
**		char **table: table of string containing all actions
**		char *motif: str motif to be counted within table
*/

int		ft_table_nb_motif(char **table, char *motif)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (table == NULL || table[i] == NULL || motif == NULL)
		return (0);
	while (table[i])
	{
		if (ft_strcmp(table[i], motif) == 0)
			nb++;
		i++;
	}
	return (nb);
}
