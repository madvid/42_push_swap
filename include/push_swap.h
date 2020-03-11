/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/11 21:37:53 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
// del
# include <stdio.h>
// del

typedef	struct	s_info
{
	size_t		tot_len;
	size_t		len;
	size_t		start;
}				t_info;

typedef	struct	s_pp
{
	size_t		permanent_len;
	int			**stack;
}				t_pp;

/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c push.c
*/
void	special_swap(t_pp *data1, t_pp *data2, int i, int j);
int		ft_swap(t_pp *data);
void	ft_s_a(t_pp *data1);
void	ft_s_b(t_pp *data2);
void	ft_swap_ss(t_pp *data1, t_pp *data2);
int		ft_push(t_pp *d_orig, t_pp *d_dest);
void	ft_p_a(t_pp *data1, t_pp *data2);
void	ft_p_b(t_pp *data1, t_pp *data2);
void	ft_rotate(t_pp *data);
void	ft_r_a(t_pp *data1);
void	ft_r_b(t_pp *data2);
void	ft_rr(t_pp *data1, t_pp *data2);
void	ft_rev_rotate(t_pp *data);
void	ft_rr_a(t_pp *data1);
void	ft_rr_b(t_pp *data2);
void	ft_rrr(t_pp *data1, t_pp *data2);

/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data, t_info info);
void	pp_print_2stack_full(t_pp data1, t_pp data2, t_info info1, t_info info2);
void	pp_print_1stack_full(t_pp data, t_info info);
void	pp_print_stack(t_pp data, t_info info);

/*
** functions for sort the table of *int
** File(s): bubble_sorts.c
*/
int		ft_issort(t_pp *data1, t_info *info1);
void	bubble_sort_simple(t_pp *data1);

void	quicksort(int **sort_lst, int index_left, int index_right);
int		permute(int **sort_lst, int left, int right, int pivot);

void	quicksort_2stacks(t_pp *data1, t_pp *data2);

/*
** Others functions
*/
void	ft_stack_split(t_pp *data1, t_pp *data2, t_info info1, t_info info2, int (*ft_order)(int, int));

/*
** temporary
*/
void	ft_print_intab(int *table, int nb_elem);

# endif
