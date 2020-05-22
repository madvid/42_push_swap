/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:02:59 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/21 16:14:58 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef enum	e_stat
{
	STAT_ERR,
	STAT_OK
}				t_stat;

void			parser(int ac, char **av, char **tab);
void			put_av_2_tab(int ac, char **av, char **tab);
int				check_args(int ac, char **av);
int				ft_isnumber_wthin_int(char *av);
char			*ft_iswithin_int(char *s);

#endif
