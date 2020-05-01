/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/30 15:25:13 by md4              ###   ########.fr       */
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
	size_t		len1;
	size_t		len2;
	size_t		start1;
	size_t		start2;
}				t_info;

typedef	struct	s_pp
{
	size_t		tot_len;
	int			**stack1;
	int			**stack2;
}				t_pp;

/*
** function(s) for initialization
** File(s): push_swap.c
*/
void	ft_initialization(t_pp **data, t_info **info, size_t total);
void	ft_fill_stacks(int **int_stack, t_pp **data, char **av, size_t total);


/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c push.c
*/
void	special_swap(t_pp *data, int i, int j);
int		ft_swap(int **data, t_info info, char a_or_b);
void	ft_s_a(t_pp *data, t_info info);
void	ft_s_b(t_pp *data, t_info info);
void	ft_swap_ss(t_pp *data, t_info info);
int		ft_push(int ***s_orig, int ***d_dest, t_info *info, char a_or_b);
void	ft_p_a(t_pp *data, t_info *info);
void	ft_p_b(t_pp *data, t_info *info);
void	ft_rotate(int **stack, t_info info, char a_or_b);
void	ft_r_a(t_pp *data, t_info info);
void	ft_r_b(t_pp *data, t_info info);
void	ft_rr(t_pp *data, t_info info);
void	ft_rev_rotate(int **stack, t_info info, char a_or_b);
void	ft_rr_a(t_pp *data, t_info info);
void	ft_rr_b(t_pp *data, t_info info);
void	ft_rrr(t_pp *data, t_info info);

/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data, t_info info, int i_stack);
void	pp_print_2stack_full(t_pp data, t_info info);
void	pp_print_1stack_full(t_pp data, t_info info, int i_stack);
void	pp_print_2_info(t_info info);


/*
** functions for min, max, average, median
** File(s): ft_stat_tools.c ft_issort.c
*/
int		ft_get_pos_min(int **stack, t_info info, char a_or_b);
int		ft_get_pos_max(int **stack, t_info info, char a_or_b);
int		ft_get_median(int *median, int **stack, size_t nb_elem);
int		ft_get_average(int *avg, int **stack, size_t nb_elem);
int		ft_issort(t_pp *data, t_info info, int croissant, char a_or_b);
int		ft_both_issort(t_pp *data, t_info info);
int		ft_comp(int nb1, int nb2, char a_or_b);
int		ft_stack_issort(int **data, t_info info, char a_or_b);


/*
** functions for sort the table of *int
** File(s): bubble_sorts.c, optimal_small_sort.c
*/
void	bubble_sort_simple(t_pp *data1);
int		ft_sort_short_stack(t_pp *data, t_info info, char a_or_b);
int		ft_sort_small_stack_a(t_pp *data, t_info info);
int		ft_sort_small_stack_b(t_pp *data, t_info info);
void	ft_sort_small_stack_a_next(t_pp *data,t_info info1);
void	ft_sort_small_stack_b_next(t_pp *data,t_info info2);
int		ft_sort_2_elem(t_pp *data, t_info info, char a_or_b);
void	ft_optimal_small_sort(t_pp *data, t_info *info);
void	ft_sort_2_length(t_pp *d, t_info *info);
void	ft_sort_3_length(t_pp *d, t_info *info);
void	ft_sort_4_length(t_pp *d, t_info *info);
void	ft_sort_5_length(t_pp *d, t_info *info);
void	quicksort(int **sort_lst, int index_left, int index_right);
void	quicksort_2stacks_init(t_pp *data1, t_pp *data2, t_info *info1, t_info *info2);
void	quicksort_2stacks(t_pp *data, t_info info, char a_or_b);

/*
** Others functions
*/
void	ft_stck_splt2b(t_pp *data, t_info *info, int (*ft_order)(int*, int**, size_t));
void	ft_stck_splt2a(t_pp *data, t_info *info, int (*ft_order)(int*, int**, size_t));
void	ft_head_back_to_top(t_pp *data, t_info *info, size_t rot_rev, char a_or_b);

/*
** Functions to manage the restacking of the to stacks when heads are sorted.
** file(s): push_back.c
*/
char	ft_not_a_or_b(char a_or_b);
void	ft_push_back(t_pp *data, t_info *info, char a_or_b);
void	ft_push_back_2_a(t_pp *data, t_info *info);
void	ft_push_back_2_b(t_pp *data, t_info *info);

void	ft_info_cpy(t_info *copy, t_info info);
void	ft_info_recover(t_info *copy, t_info *info);
void	ft_bottom_up_rotate(t_pp *data, t_info info, char a_or_b);


/*
** temporary
*/
void	ft_print_intab(int *table, int nb_elem);

# endif
