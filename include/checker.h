/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:14 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/03 15:35:45 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** Functions to read and check the actions given by user ('sa', 'sb', ...).
*/
const char	**ft_init_tab_actions(void);
int			ft_read_actions(const char **actions);
int			ft_check_actions(char *buf, const char **actions);

#endif