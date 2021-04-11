/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:42:48 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 19:44:17 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	side_of_the_world(char side, t_all *all)
{
	if (side == 'N')
		all->plr->dir = M_PI_2 * 3;
	if (side == 'E')
		all->plr->dir = 0;
	if (side == 'S')
		all->plr->dir = M_PI_2;
	if (side == 'W')
		all->plr->dir = M_PI;
}

int	check_flag(int flag)
{
	int	i;

	if (flag == 4)
		i = 1;
	else
		i = 2;
	return (i);
}
