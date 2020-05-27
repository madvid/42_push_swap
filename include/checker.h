/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:14 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/27 00:58:04 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#include <stdlib.h>

# ifndef S_INFO
#  define S_INFO
typedef	struct	s_info
{
	size_t		tot_len;
	size_t		len1;
	size_t		len2;
	size_t		start1;
	size_t		start2;
}				t_info;
# endif
# ifndef S_PP
#  define S_PP
typedef	struct	s_pp
{
	size_t		tot_len;
	int			**stack1;
	int			**stack2;
	char		**buf_act;
	char		**act_list;
	size_t		i_act;
	size_t		nb_actions;
}				t_pp;
# endif

/*
** Functions to read and check the actions given by user ('sa', 'sb', ...).
*/
char			*ft_check_action(char *action);
void			ft_perform_action(t_pp *data, t_info *info, char *action);
int				ft_parse_and_init(int ac, char **av, t_pp **data, t_info **info, int **stack);

/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c,  push.c, rotate.c, rev_rotate.c
*/
int		ft_push(int ***s_orig, int ***s_dest, t_info *info, char a_or_b);
int		ft_p_a(t_pp *data, t_info *info);
int		ft_p_b(t_pp *data, t_info *info);
int		ft_swap(int **data, t_info info, char a_or_b);
int		ft_s_a(t_pp *data, t_info info);
int		ft_s_b(t_pp *data, t_info info);
int		ft_swap_ss(t_pp *data, t_info info);
void	ft_rotate(int **stack, t_info info, char a_or_b);
int		ft_r_a(t_pp *data, t_info info);
int		ft_r_b(t_pp *data, t_info info);
int		ft_rr(t_pp *data, t_info info);
void	ft_rev_rotate(int **stack, t_info info, char a_or_b);
int		ft_rr_a(t_pp *data, t_info info);
int		ft_rr_b(t_pp *data, t_info info);
int		ft_rrr(t_pp *data, t_info info);


#endif
