/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:44:49 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/22 22:14:22 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
** FONCTION : permute.
** PARAMETRES :	int **sort_lst : adresse d'un tableau (*int).
**				int left : indice gauche du tableau.
**				int right : indice droit du tableau.
**				int pivot : valeur pivot au sein du tableau.
** DESCRIPTION :
**		Les éléments de sort_lst à gauche de la position de pivot étant plus
**		petits que pivot sont permutés avec les éléments à droite de la position
**		pivot étant plus grands que pivot.
**		À la fin, on se retrouve avec à gauche de pivot des valeurs plus grandes
**		que le pivot et à droite du pivot, des valeurs plus petites que pivot.
** RETOUR :
**		La position de pivot (l'indice) au sein du tableau.
*/

int		permute(int **sort_lst, int left, int right, int pivot)
{
	int		tmp;

	while (left <= right)
	{
		while ((*sort_lst)[left] > pivot)
			left++;
		while ((*sort_lst)[right] < pivot)
			right--;
		if (left <= right)
		{
			tmp = (*sort_lst)[right];
			(*sort_lst)[right] = (*sort_lst)[left];
			(*sort_lst)[left] = tmp;
			left++;
			right--;
		}
	}
	return (left);
}

/*
** FONCTION : quicksort
** PARAMETRES :	int **sort_lst : adresse d'un tableau (*int).
**				int index_left : nb d'éléments de *sort_lst.
**				int index_right : nb d'éléments de *sort_lst.
** DESCRIPTION :
**		Tri la liste de nombres via l'algo quicksort.
** RETOUR :
**		RIEN.
*/

void	quicksort(int **sort_lst, int index_left, int index_right)
{
	int		pivot;
	int		index;

	if (index_left >= index_right)
		return ;
	pivot = (*sort_lst)[(index_left + index_right) / 2];
	index = permute(sort_lst, index_left, index_right, pivot);
	quicksort(sort_lst, index_left, index - 1);
	quicksort(sort_lst, index, index_right);
}
