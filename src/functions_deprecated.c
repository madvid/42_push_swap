/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_deprecated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:13:22 by md4               #+#    #+#             */
/*   Updated: 2020/05/07 15:20:45 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function: ft_head_back_to_top
** PARAMETERS:	t_pp *data: data struct containing stack of number.
**				t_info *info: data struct containing stack info.
**				int rot_rev: number of rotations performed during split.
**				a_or_b: tag to know which stack is treating.
** DESCRIPTION:
** 	Performs reverse rotation or rotatio n to bring back number initially on
**	top of the stack.
*/

void	ft_head_back_to_top(t_pp *data, t_info *info, size_t rot_rev,
		char a_or_b)
{
	void	(*ft_rr)(t_pp*, t_info);
	void	(*ft_r)(t_pp*, t_info);
	size_t	len;

	ft_r = (a_or_b == 'a') ? &ft_r_a : &ft_r_b;
	ft_rr = (a_or_b == 'a') ? &ft_rr_a : &ft_rr_b;
	len = (a_or_b == 'a') ? info->len1 : info->len2;
	if ((len / 2) > rot_rev)
		while (rot_rev <= len)
		{
			ft_r(data, *info);
			rot_rev++;
		}
	else
		while (rot_rev > 0)
		{
			ft_rr(data, *info);
			rot_rev--;
		}
}