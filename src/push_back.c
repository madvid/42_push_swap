/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 10:47:06 by md4               #+#    #+#             */
/*   Updated: 2020/03/29 12:00:35 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION: ft_push_back_2_a
** ARGUMENTS:	t_pp *d_a
** 				t_pp *d_b
** 				t_info *i_a
** 				t_info *i_b
** DESCRIPTION:
** 	Push back all the elements of stack B on the stack A.
** RETURN: None.
*/

void	ft_push_back_2_a(t_pp *d_a, t_pp *d_b, t_info *i_a, t_info *i_b)
{
	size_t	s;

	s = i_b->len;
	printf("____ ft_push_back_2_a\n");
	while (s > 0)
	{
		ft_p_a(d_a, d_b, i_a, i_b);
		s--;
	}
}

/*
** FUNCTION: ft_push_back_2_b
** ARGUMENTS:	t_pp *d_a
** 				t_pp *d_b
** 				t_info *i_a
** 				t_info *i_b
** DESCRIPTION:
** 	Push back all the elements of stack A on the stack B.
** RETURN: None.
*/

void	ft_push_back_2_b(t_pp *d_a, t_pp *d_b, t_info *i_a, t_info *i_b)
{
	size_t	s;

	s = i_a->len;
	printf("____ ft_push_back_2_b\n");
	while (s > 0)
	{
		ft_p_b(d_a, d_b, i_a, i_b);
		s--;
	}
}

/*
** FUNCTION: ft_push_back
** ARGUMENTS:	t_pp *d_a
** 				t_pp *d_b
** 				t_info *i_a
** 				t_info *i_b
**              char a_or_b
** DESCRIPTION:
** 	Push back all the elements of stack A or B on the stack B or A
**  depending on a_or_b.
** RETURN: None.
*/

void	ft_push_back(t_pp *d_a, t_pp *d_b, t_info *i_a, t_info *i_b, char a_or_b)
{
	if (a_or_b == 'a')
		ft_push_back_2_b(d_a, d_b, i_a, i_b);
	if (a_or_b == 'b')
		ft_push_back_2_a(d_a, d_b, i_a, i_b);
}