/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:22:26 by md4               #+#    #+#             */
/*   Updated: 2020/04/30 15:25:31 by md4              ###   ########.fr       */
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

void	ft_info_recover(t_info *copy, t_info *info)
{
	info->tot_len = copy->tot_len;
	info->len1 = copy->len1;
	info->len2 = copy->len2;
	info->start1 = copy->start1;
	info->start2 = copy->start2;
}