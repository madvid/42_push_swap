/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 10:47:06 by md4               #+#    #+#             */
/*   Updated: 2020/04/22 22:09:03 by md4              ###   ########.fr       */
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

void	ft_push_back_2_a(t_pp *data, t_info *info)
{
	size_t	s;

	s = info->len2;
	while (s > 0)
	{
		ft_p_a(data, info);
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

void	ft_push_back_2_b(t_pp *data, t_info *info)
{
	size_t	s;

	s = info->len1;
	while (s > 0)
	{
		ft_p_b(data, info);
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

void	ft_push_back(t_pp *data, t_info *info, char a_or_b)
{
	if (a_or_b == 'a')
		ft_push_back_2_b(data, info);
	if (a_or_b == 'b')
		ft_push_back_2_a(data, info);
}
