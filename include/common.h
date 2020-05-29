/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:02:59 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/29 02:30:49 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>

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
	char		**act_list;
	size_t		i_act;
	size_t		nb_actions;
}				t_pp;
# endif

/*
** functions for parsing:
** file(s): parser.c, check_args.c
*/

int				parser(int ac, char **av, char ***tab);
int				ft_is_digits_and_spaces(char *str);
void			put_av_2_tab(int ac, char **av, char ***tab);
int				check_args(int ac, char **av);
int				ft_isall_wthin_int(char **tab);
int				ft_iswithin_int(char *s);

/*
** function(s) for initialization
** File(s): common_tools.c
*/
int				ft_initialization(t_pp **data, t_info **info, size_t total);
void			ft_destroy(t_pp *data, t_info *info, int *int_stack,
				char **tab);
void			ft_fill_stacks(int **int_stack, t_pp **data, char **av,
				size_t total);
void			pp_print_2stack_full(t_pp data, t_info info);
void			pp_print_1stack_full(t_pp data, t_info info, int i_stack);

/*
** Functions to check if it is sortted and statistic related functions
** Files: ft_issort.c
*/
int				ft_issort(t_pp *data, t_info info, int croissant, char a_or_b);

#endif
