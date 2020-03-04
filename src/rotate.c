/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:45:42 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 19:14:05 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	ft_rotate(t_pp *data)
{
	int			*tmp;
	size_t		i;

	i = data->t_len - data->len;
	tmp = data->stack[i];
	while (i + 1 < data->t_len)
	{
		data->stack[i] = data->stack[i + 1];
		i++;
	}
	data->stack[i] = tmp;
}

void	ft_r_a(t_pp *dataA)
{
	ft_rotate(dataA);
	write(1,"ra\n", 3);
}

void	ft_r_b(t_pp *dataB)
{
	ft_rotate(dataB);
	write(1,"rb\n", 3);
}

void	ft_rr(t_pp *dataA, t_pp *dataB)
{
	ft_rotate(dataB);
	ft_rotate(dataA);
	write(1,"rr\n", 3);
}

void	ft_rev_rotate(t_pp *data)
{
	int			*tmp;
	size_t		i;

	i = data->t_len;
	tmp = data->stack[data->t_len - 1];
	while (i > data->t_len - data->len)
	{
		data->stack[i] = data->stack[i - 1];
		i--;
	}
	data->stack[i] = tmp;
}

void	ft_rr_a(t_pp *dataA)
{
	ft_rev_rotate(dataA);
	write(1,"rra\n", 4);
}

void	ft_rr_b(t_pp *dataB)
{
	ft_rev_rotate(dataB);
	write(1,"rrb\n", 4);
}

void	ft_rrr(t_pp *dataA, t_pp *dataB)
{
	ft_rev_rotate(dataB);
	ft_rev_rotate(dataA);
	write(1,"rrr\n", 4);
}