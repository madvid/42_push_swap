/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:15:13 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/19 19:30:38 by md4              ###   ########.fr       */
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

/*
void	quicksort_2stacks(t_pp *data1, t_pp *data2, t_info info1, t_info info2, char a_or_b)
{
	t_info	cpy1;
	t_info	cpy2;
	int		sorted;

	sorted = 0;
	printf("\n >>> a_or_b = %c <<<", a_or_b);
	pp_print_2stack_full(*data1, *data2, info1, info2);
	// triage des sommets des stacks 
	sorted += (info1.len <= 3 && info1.len > 1) ?
		ft_sort_short_stack(data1, info1, 'a') : 0;
	sorted += (info2.len <= 3 && info2.len > 1) ?
		ft_sort_short_stack(data2, info2, 'b') : 0;
	
	// Operation de push back
	(sorted != 0 || ( ft_issort(data1, info1, 0) == 1
	&& ft_issort(data2, info2, 1) == 1)) ?
	ft_push_back(data1, data2, &info1, &info2, a_or_b) : 0;
	if (sorted != 0
	|| ( ft_issort(data1, info1, 0) == 1 && ft_issort(data2, info2, 1) == 1))
		return ;

	// Partie pour split en fonction de a_or_b
	ft_info_double_cpy(info1, info2, &cpy1, &cpy2);
	printf(" >>> a_or_b = %c <<<", a_or_b);
	pp_print_2stack_full(*data1, *data2, info1, info2);
	if (info1.len > 3 && a_or_b == 'a' && ft_issort(data1, info1, 0) != 1)
	{
		ft_stck_splt2b(data1, data2, &info1, &info2, ft_get_median);
		quicksort_2stacks(data1, data2, info1, info2, 'b');
		printf(" >>> a_or_b = %c <<<", a_or_b);
		pp_print_2stack_full(*data1, *data2, info1, info2);
		ft_info_double_cpy(cpy1, cpy2, &info1, &info2);
		if (info2.len > 3 && ft_issort(data2, info2, 1) != 1)
			quicksort_2stacks(data1, data2, info1, info2, 'b');	
	}
	if (info2.len > 3 && a_or_b == 'b' && ft_issort(data2, info2, 1) != 1)
	{
		ft_stck_splt2a(data1, data2, &info1, &info2, ft_get_median);
		quicksort_2stacks(data1, data2, info1, info2, 'a');
		printf(" >>> a_or_b = %c <<<", a_or_b);
		pp_print_2stack_full(*data1, *data2, info1, info2);
		ft_info_double_cpy(cpy1, cpy2, &info1, &info2);
		if (info1.len > 3 && ft_issort(data1, info1, 0) != 1)
			quicksort_2stacks(data1, data2, info1, info2, 'a');
	}
	if (ft_issort(data1, info1, 0) == 1 && ft_issort(data2, info2, 1) == 1)
	{
		printf("Last push back before finish this recursion\n");
		a_or_b == 'b' ? ft_push_back_2_b(data1, data2, &info1, &info2) :
			ft_push_back_2_a(data1, data2, &info1, &info2);
	}
	printf("____ FIN de quicksort ____\n");
}*/

void	quicksort_2stacks(t_pp *data, t_info info, char a_or_b)
{
	t_info	cpy;
	int		sorted;

	sorted = 0;
	// Trie de la stack a(/b) si sa longueure est inferieure à 3 et supérieure à 0.
	sorted += (info.len1 > 0 && info.len1 <= 3) ?
		ft_sort_short_stack(data, info, 'a') : 0;
	sorted += (info.len2 > 0 && info.len2 <= 3) ?
		ft_sort_short_stack(data, info, 'b') : 0;
	// Si les stacks étaient deja triees ou s'ils viennent d'être triées alors on push back.
	if (sorted > 1 || (ft_issort(data, info, 1, 'a') == 1 && ft_issort(data, info, 0, 'b') == 1))
	{
		ft_push_back(data, &info, a_or_b);
		return ;
	}
	// Copie des données dans info1 et info2 pour le retour de récurssif 
	ft_info_double_cpy(info, &cpy);
	write(1, "ici 2\n", 6);
	if (info.len1 > 3 && a_or_b == 'a' && ft_issort(data, info, 1, 'a') != 1)
	{
		write(1, "ici 3\n", 6);
		ft_stck_splt2b(data, &info, ft_get_median);
		write(1, "ici 4\n", 6);
		pp_print_2stack_full(*data, info);
		write(1, "ici 5\n", 6);
		quicksort_2stacks(data, info, 'b');
		write(1, "ici 6\n", 6);
		ft_info_double_cpy(cpy, &info);
		write(1, "ici 7\n", 6);
		pp_print_2stack_full(*data, info);
	}
	if (info.len2 > 3 && a_or_b == 'b' && ft_issort(data, info, 0, 'b') != 1)
	{
		ft_stck_splt2a(data, &info, ft_get_median);
		printf(" >>>#3 a_or_b = %c <<<", a_or_b);
		pp_print_2stack_full(*data, info);
		quicksort_2stacks(data, info, 'a');
		ft_info_double_cpy(cpy, &info);
		printf(" >>>#4 a_or_b = %c <<<", a_or_b);
		pp_print_2stack_full(*data, info);
	}
	write(1, "ici 6\n", 6);
	printf("\n >>>#4.5 a_or_b = %c <<<", a_or_b);
	//pp_print_2stack_full(*data1, *data2, info1, info2);
	if (a_or_b == 'a' && ft_issort(data, info, 0, 'b') != 1)
		quicksort_2stacks(data, info, 'b');
	if (a_or_b == 'b' && ft_issort(data, info, 1, 'a') != 1)
		quicksort_2stacks(data, info, 'a');
	if (a_or_b == 'a' && ft_issort(data, info, 0, 'b') == 1 && ft_issort(data, info, 1, 'a') == 1)
		ft_push_back(data, &info, 'b');
	if (a_or_b == 'b' && ft_issort(data, info, 1, 'a') == 1 && ft_issort(data, info, 0, 'b') == 1)
		ft_push_back(data, &info, 'a');
	printf("\n >>>#5 a_or_b = %c <<<", a_or_b);
	//pp_print_2stack_full(*data1, *data2, info1, info2);
	printf("\n____ FIN de quicksort ____\n");
}