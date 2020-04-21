/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:22:26 by md4               #+#    #+#             */
/*   Updated: 2020/04/19 19:28:29 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_info_double_cpy(t_info info, t_info *tp)
{
	tp->tot_len = info.tot_len;
	tp->len1 = info.len1;
	tp->len2 = info.len2;
	tp->start1 = info.start1;
	tp->start2 = info.start2;
}
