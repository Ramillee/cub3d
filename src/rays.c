/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:18:11 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 14:32:24 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static float	ft_cast_rays_util(t_all *all, float start)
{
	all->plr->ray->x = all->plr->x;
	all->plr->ray->y = all->plr->y;
	while (all->map[(int)(all->plr->ray->y / SCALE)]
		[(int)(all->plr->ray->x / SCALE)] != '1')
	{
		all->plr->ray->old_x = all->plr->ray->x;
		all->plr->ray->old_y = all->plr->ray->y;
		all->plr->ray->x += cos(start) / 10;
		all->plr->ray->y += sin(start) / 10;
	}
	start += all->plr->ray->ray_step;
	all->plr->ray->ray_len = sqrt(pow(all->plr->ray->x - all->plr->x, 2)
			+ pow(all->plr->ray->y - all->plr->y, 2))
		* cos(all->plr->dir - start);
	return (start);
}

void	ft_cast_rays(t_all *all)
{
	float	x;
	float	start;
	float	end;
	int		i;

	x = 0;
	i = -1;
	start = all->plr->dir - M_PI_2 / 3;
	end = all->plr->dir + M_PI_2 / 3;
	while (start <= end)
	{
		++i;
		start = ft_cast_rays_util(all, start);
		paint_line(all, x++);
		all->lens[i] = all->plr->ray->ray_len;
	}
	math_sprite(all, all->count_sprite);
}
