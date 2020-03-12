/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:15:13 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/12 17:24:33 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/*
** FUNCTION : ft_get_average.
** PARAMETRES :	int **stack : table of *int.
**				size_t nb_elem : nb elements of **stack.
** DESCRIPTION :
**		Get the average of the list.
** RETURN :
**		value of the average of the integers list.
*/

int		ft_get_average(int *avg, int **stack, size_t nb_elem)
{
	size_t		k;

	k = 0;
	if (nb_elem == 0)
		return(0);
	while (stack[k] == NULL)
		k++;
	while (k < nb_elem)
	{
		*avg += *stack[k];
		k++;
	}
	*avg = *avg / ((int)nb_elem - 1);
	return (1);
}

/*
** FUNCTION : ft_get_median.
** PARAMETERS :	int *median: int pointer, place to stock calculated median.
**				int **stack : table of *int.
**				size_t nb_elem : nb elements of **stack.
** DESCRIPTION :
**		Get the median of the list of number by sorting it first.
** RETURN :
**		0 if any problem is encountered.
**		1 if everything is fine.
*/

int		ft_get_median(int *median, int **stack, size_t nb_elem)
{
	size_t		k;
	int			*tmp_lst;
	int			start;

	k = 0;
	start = 0;
	if (!(tmp_lst = (int*)malloc(sizeof(int) * nb_elem)) || nb_elem == 0)
		return (0);
	while (stack[start] == NULL)
		start++;
	while (k < nb_elem)
	{
		tmp_lst[k] = *stack[start + k];
		k++;
	}
	quicksort(&tmp_lst, 0, (int)(nb_elem - 1));
	*median = tmp_lst[(int)(nb_elem - 1) / 2];
	free((void*)tmp_lst);
	return (1);
}


/*
** FUNCTION : quicksort_2stacks
** PARAMETRES :	t_pp *data1 : 1st struct of data holding the 1st stack.
**				t_pp *data2 : 2nd struct of data holding the 2nd stack.
** DESCRIPTION :
**		Sort the stack of .
** RETOUR :
**		RIEN.
*/

void	quicksort_2stacks(t_pp *data1, t_pp *data2, t_info info1, t_info info2, int a_or_b)
{	
	pp_print_2stack_full(*data1, *data2, info1, info2);
	if (info1.len > 2 && a_or_b == 1)
	{
		pp_print_2_info(info1, info2);
		ft_stck_splt2b(data1, data2, &info1, &info2, ft_get_median);
		quicksort_2stacks(data1, data2, info1, info2, 0);
	}
	if (info2.len > 2 && a_or_b == 0)
	{
		pp_print_2_info(info1, info2);
		ft_stck_splt2a(data1, data2, &info1, &info2, ft_get_median);
		quicksort_2stacks(data1, data2, info1, info2, 1);
	}
}