/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 10:47:06 by md4               #+#    #+#             */
/*   Updated: 2020/04/30 13:39:04 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_not_a_or_b
** Argument(s):	char a_or_b: char 'a' or 'b'
** Description:
** 	Reverse the variable a_or_b.
** Return:
**	'b' if a_or_b is 'a'.
**	'a' if a_or_b is 'b'.
*/

char	ft_not_a_or_b(char a_or_b)
{
	return ((a_or_b == 'a') ? 'b' : 'a');
}

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
	printf("- - - longueur des piles en cours: len_s1 = %ld   len_s2 = %ld\n", info->len1, info->len2);
	if (a_or_b == 'a')
		ft_push_back_2_b(data, info);
	if (a_or_b == 'b')
		ft_push_back_2_a(data, info);
}
