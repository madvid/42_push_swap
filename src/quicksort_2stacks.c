/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:15:13 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/22 19:48:40 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION : quicksort_2stacks
** PARAMETRES :	t_pp *data1 : 1st struct of data holding the 1st stack.
**				t_pp *data2 : 2nd struct of data holding the 2nd stack.
** DESCRIPTION :
**		Sort the stack of .
** RETOUR :
**		RIEN.
*/

void	quicksort_2stacks(t_pp *data, t_info info, char a_or_b)
{
	t_info	cpy;
	int		sorted;

	sorted = 0;
	// Trie stack a(/b) si longueure est inferieure à 3 et sup à 0.
	sorted += (info.len1 > 0 && info.len1 <= 3) ?
		ft_sort_short_stack(data, info, 'a') : 0;
	sorted += (info.len2 > 0 && info.len2 <= 3) ?
		ft_sort_short_stack(data, info, 'b') : 0;
	// Si stacks deja triees ou s'ils viennent d'être triées alors push back.
	if (sorted > 1 || (ft_both_issort(data, info) == 1))
	{
		ft_push_back(data, &info, a_or_b);
		return ;
	}
	// Copie des données dans info1 et info2 pour le retour de récurssif
	ft_info_double_cpy(info, &cpy);
	if (info.len1 > 3 && a_or_b == 'a' && ft_issort(data, info, 1, 'a') != 1)
	{
		ft_stck_splt2b(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'b');
		ft_info_double_cpy(cpy, &info);
	}
	if (info.len2 > 3 && a_or_b == 'b' && ft_issort(data, info, 0, 'b') != 1)
	{
		ft_stck_splt2a(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'a');
		ft_info_double_cpy(cpy, &info);
	}
	if (a_or_b == 'a' && ft_issort(data, info, 0, 'b') != 1)
		quicksort_2stacks(data, info, 'b');
	if (a_or_b == 'b' && ft_issort(data, info, 1, 'a') != 1)
		quicksort_2stacks(data, info, 'a');
	if (a_or_b == 'a' && ft_both_issort(data, info) == 1)
		ft_push_back(data, &info, 'b');
	if (a_or_b == 'b' && ft_both_issort(data, info) == 1)
		ft_push_back(data, &info, 'a');
}
