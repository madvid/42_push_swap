/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/03 20:56:40 by weilin           ###   ########.fr       */
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

void pt_tpp(t_pp *add)
{
	size_t i = add->start;

	size_t lentmp = add->len;

	printf("total stack_pp len=%zu\n", add->len);
	printf("stack_pp starts at stack[%d]\n", add->start);

	while (lentmp)
	{
		if (add->len - i < 1)
			i -= add->len;
		printf("stack_pp[%zu]=%d\n", add->len - lentmp, *add->pp[i]);
		lentmp--;
		i++;
	}
}

int main2(int ac, char **av)
{
	int control = 1;

	if (ac < 2)
	{
		control += write(1, "EMPTY\n", 6);
		printf("control=%d\n", control);
	}
	// printf("ac=%d\n",ac);

	if (!ft_check_args(ac - 1, av))
	{
		control += write(1, "Error\n", 6);
		printf("ft_check_args=%d\n", ft_check_args(ac - 1, av));
		printf("control=%d\n", control);
	}
	if (control != 1)
		return (0);

	int total = ac - 1;
	int *stack = (int *)malloc(sizeof(int) * (total));
	t_pp a;

	a.start = 0;
	a.pp = (int **)malloc(sizeof(int *) * (total));
	a.len = total;
	// int **pb=(int*)malloc(sizeof(int*)*(total));

	if (control == 1)
	{
		while (total > 0)
		{
			stack[total - 1] = atoi(av[total]);
			a.pp[total - 1] = &stack[total - 1];
			total--;
		}
	}
	printf("total num=%d\n", ac - 1);
	while (total < ac - 1)
	{
		printf("stack[%d]=%d\n", total, stack[total]);
		total++;
	}
	a.start = (total > 1) ? 1 : 0;
	pt_tpp(&a);
	// printf("sizeof(int)=%lu\n",sizeof(int));=4
	// printf("sizeof(int*)=%lu\n",sizeof(int*));=8
	// printf("sizeof(size_t)=%lu\n",sizeof(size_t));=8
}