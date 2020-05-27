/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:22:26 by md4               #+#    #+#             */
/*   Updated: 2020/05/24 02:38:18 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*
** Function: ft_info_cpy
** Parameters:
**		t_info *copy:
**		t_info *info:
** Description:
**	Dupplicate the information stock in info object to copy object.
** Return:
**	None.
*/

void	ft_info_cpy(t_info *copy, t_info info)
{
	copy->tot_len = info.tot_len;
	copy->len1 = info.len1;
	copy->len2 = info.len2;
	copy->start1 = info.start1;
	copy->start2 = info.start2;
}

/*
** Function: ft_info_back
** Parameters:
**		t_info *copy:
**		t_info *info:
** Description:
**	Allow to copy back info in "copy" before split2b/split2a process.
** Return:
**	None.
*/

void	ft_info_back(t_info *copy, t_info *info)
{
	info->tot_len = copy->tot_len;
	info->len1 = copy->len1;
	info->len2 = copy->len2;
	info->start1 = copy->start1;
	info->start2 = copy->start2;
}

/*
** Function: ft_info_recover
** Parameters:
**		t_info *info:
**		t_pp *data:
** Description:
**	Allow to recover exploitable info to naviguate through the staks.
**	Process is to scan data->stack1 and data->stack2 to find non-NULL
**	pointers.
** Return:
**	None.
*/

void	ft_info_recover(t_info *info, t_pp *data)
{
	if (data->stack2[info->start2] == NULL)
		while (data->stack2[info->start2] == NULL && info->len2 > 1)
		{
			info->start2++;
			info->len2--;
		}
	if (data->stack2[info->start2] == NULL)
		while (data->stack1[info->start1 - 1] != NULL && info->start1 > 0)
		{
			info->start1--;
			info->len1++;
		}
	if (data->stack1[info->start1] == NULL)
	{
		while (data->stack1[info->start1] == NULL && info->len1 > 0)
		{
			info->start1++;
			info->len1--;
		}
		while (data->stack2[info->start2 - 1] != NULL && info->start2 > 0)
		{
			info->start2--;
			info->len2++;
		}
	}
}
