/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 18:55:24 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"
# include "checker.h" 

typedef	struct	s_pp
{
	size_t		len;
	size_t		t_len;
	int			**stack;
}				t_pp;

/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c push.c
*/
void	special_swap(t_pp *data1, t_pp *data2, int i, int j);
void	ft_swap(t_pp *data);
void	ft_swap_ss(t_pp *data1, t_pp *data2);
int		ft_push(t_pp *d_orig, t_pp *d_dest);
void	ft_p_a(t_pp *dataA, t_pp *dataB);
void	ft_p_b(t_pp *dataA, t_pp *dataB);
void	ft_rotate(t_pp *data);
void	ft_r_a(t_pp *dataA);
void	ft_r_b(t_pp *dataB);
void	ft_rr(t_pp *dataA, t_pp *dataB);
void	ft_rev_rotate(t_pp *data);
void	ft_rr_a(t_pp *dataA);
void	ft_rr_b(t_pp *dataB);
void	ft_rrr(t_pp *dataA, t_pp *dataB);

/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data);
void	pp_print_2stack_full(t_pp data1, t_pp data2);
void	pp_print_1stack_full(t_pp data);
void	pp_print_stack(t_pp data);

# endif
