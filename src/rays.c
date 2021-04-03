/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:18:11 by atweek            #+#    #+#             */
/*   Updated: 2021/04/03 11:08:10 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_cast_rays(t_all *all)
{
	float x;
	float start;
	float end;

	x = 0;
	all->plr->ray->ray_step = (M_PI / 3) / WIGHT;
	
	start = all->plr->dir - M_PI_2 / 3; // начало веера лучей
	end = all->plr->dir + M_PI_2 / 3; // край веера лучей
	
  while (start <= end)
	{
		all->plr->ray-> x = all->plr->x; // каждый раз возвращаемся в точку начала
		all->plr->ray->y = all->plr->y;
		while (all->map[(int)(all->plr->ray->y / SCALE)][(int)(all->plr->ray->x / SCALE)] != '1')
		{
			all->plr->ray->old_x = all->plr->ray->x;
			all->plr->ray->old_y = all->plr->ray->y;
			all->plr->ray->x += cos(start) / 10;
			all->plr->ray->y += sin(start) / 10;
		}
		start += all->plr->ray->ray_step;
		all->plr->ray->ray_len = sqrt(pow(all->plr->ray->x - all->plr->x,2) + pow(all->plr->ray->y - all->plr->y,2)) * cos(all->plr->dir - start);
		paint_line(all,x++);
	}
	math_sprite(all,all->count_sprite);
}