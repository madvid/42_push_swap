/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_intab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:13:59 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/11 14:59:51 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FONCTION : FT_print_intab.
** PARAMETRES :	int **table : tableau de int.
**				int nb_elem : nb d'éléments de table.
** DESCRIPTION :
**		Affiche l'ensemble des éléments de table.
** RETOUR :
**		RIEN.
*/

void	ft_print_intab(int *table, int nb_elem)
{
	int		k;

	k = 0;
	ft_putstr("tableau:\n");
	while (k < nb_elem)
	{
		ft_putstr("__");
		ft_putnbr(table[k]);
		k++;
	}
	ft_putstr("\n");
}