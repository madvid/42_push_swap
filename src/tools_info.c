/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:22:26 by md4               #+#    #+#             */
/*   Updated: 2020/05/10 13:35:28 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_info_cpy(t_info *copy, t_info info)
{
	copy->tot_len = info.tot_len;
	copy->len1 = info.len1;
	copy->len2 = info.len2;
	copy->start1 = info.start1;
	copy->start2 = info.start2;
}

void	ft_info_back(t_info *copy, t_info *info)
{
	info->tot_len = copy->tot_len;
	info->len1 = copy->len1;
	info->len2 = copy->len2;
	info->start1 = copy->start1;
	info->start2 = copy->start2;
}


void	ft_info_recover(t_info *info, t_pp *data)
{
	//printf("info recover\n");
	if (data->stack2[info->start2] == NULL)
	{
		while (data->stack2[info->start2] == NULL && info->len2 > 0)
		{
			info->start2++;
			info->len2--;
		}
		while (data->stack1[info->start1 - 1] != NULL && info->start1 > 0)
		{
			info->start1--;
			info->len1++;
		}
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
	/*if (info->len1 == 0)
		info->len1 = info->tot_len - info->len2;
	if (info->len2 == 0)
		info->len2 = info->tot_len - info->len1;
	pp_print_2_info(*info);*/
}