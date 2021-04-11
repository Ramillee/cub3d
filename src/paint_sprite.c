/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:09:30 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 08:08:29 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	paint_sp(t_all *all, int a)
{
	int		i;
	int		j;
	float	w;

	w = ((float) all->text[4]->height / all->sp[a].screen_size);
	i = 0;
	while (i < all->sp[a].screen_size)
	{
		if (all->sp[a].h + i >= all->info->w || all->sp[a].h + i < 0)
		{
			i++;
			continue ;
		}
		j = 0;
		while (j < all->sp[a].screen_size)
		{
			if (all->sp[a].v + j >= all->info->h || all->sp[a].v + j < 0)
			{
				j++;
				continue ;
			}
			if (all->lens[(int)(all->sp[a].h + i)] > all->sp[a].dist)
				if ((pixel_get(all, i * w, j * w, 4)) != 0)
					my_mlx_pixel_put(all, all->sp[a].h + i,
						all->sp[a].v + j, pixel_get(all, i * w, j * w, 4));
			j++;
		}
		i++;
	}
}

int	count_sprite(t_all *all)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (all->map[j])
	{
		while (all->map[j][i])
		{
			if (all->map[j][i] == '2')
			{
				count++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

void	math_sprite(t_all *all, int count)
{
	int	a;

	a = 0;
	while (a < count)
	{
		all->sp[a].dist = sqrt(pow(all->plr->x - all->sp[a].x, 2)
				+ pow(all->plr->y - all->sp[a].y, 2));
		all->sp[a].screen_size = SCALE / all->sp[a].dist * 500;
		all->sp[a].dir = atan2f(all->sp[a].y - all->plr->y, all->sp[a].x
				- all->plr->x);
		while (all->sp[a].dir - all->plr->dir > M_PI)
			all->sp[a].dir -= 2 * M_PI;
		while (all->sp[a].dir - all->plr->dir < -M_PI)
			all->sp[a].dir += 2 * M_PI;
		all->sp[a].h
			= (all->sp[a].dir - all->plr->dir) * (all->info->w) / (M_PI / 3)
			+ (all->info->w) / 2 - all->sp[a].screen_size / 2;
		all->sp[a].v = all->info->h / 2 - all->sp[a].screen_size / 500;
		a++;
	}
	a = -1;
	sort(all);
	while (++a < count)
		paint_sp(all, a);
}
