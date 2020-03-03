/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/03 15:57:27 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "common.h"

/*
** Function: ft_stock_nb
** Arguments:	int n: number of arguments
** 				char **av: all the number to stock
** Description:
** 	Convert the string numbers to integer and stock all the number in a table
** 	of int.
** Return:
**	NULL if something wrong comes up.
**	int *tab: a table of int.
*/

int		*ft_stock_nb(int n, char **av)
{

}

int		main(int ac, char **av)
{	int		*tab;
	
	if (ft_check_args(ac, av) == (int)STAT_ERR)
		return (0);
	
	tab = ft_stock_nb(ac - 1, av);
	
	return (0);
}