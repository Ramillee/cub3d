/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:21:10 by atweek            #+#    #+#             */
/*   Updated: 2021/03/31 23:14:22 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int    my_mlx_pixel_get(t_all *all_st, int x, int y,int i)
{
	char    *dst;
	dst = all_st->textures[i]->addr + (y * all_st->textures[i]->line_l + x * (all_st->textures[i]->bpp / 8));
	return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}


void paint_line(t_all *all,int x)
{
	int y;
	double wall;
	double sky;
	double hitx;
	double hity;
	int color;
	static int i; 

	hitx = (all->plr->ray->x / 32) - (int)(all->plr->ray->x / 32);
	hity = (all->plr->ray->y / 32)	 - (int)(all->plr->ray->y / 32);
	y = 0;
	wall = (HEIGHT / all->plr->ray->ray_len) * 32;
	sky = HEIGHT / 2 - wall / 2;
	int j = 0;

	if (sky < 0)
		j += fabs(sky);
	else
		while (y < sky && y < HEIGHT - 1)
			my_mlx_pixel_put(all->win, x, y++, 0xFFFFFF);
	while (y < wall + sky && y < HEIGHT - 1)
	{
		if (((int)  all->plr->ray->x == (int) all->plr->ray->old_x) && (int) all->plr->ray->old_y - (int) all->plr->ray->y > 0)
			i = 0;
		else if (((int) all->plr->ray->x == (int) all->plr->ray->old_x) && (int) all->plr->ray->old_y - (int) all->plr->ray->y < 0)
			i = 1;
		else if (((int) all->plr->ray->y == (int) all->plr->ray->old_y) && (int) all->plr->ray->old_x - (int) all->plr->ray->x < 0)
			i = 2;
		else if (((int) all->plr->ray->y == (int) all->plr->ray->old_y) && (int) all->plr->ray->old_x - (int) all->plr->ray->x > 0)
			i = 3;
		if (i == 0 || i == 1)
			color = my_mlx_pixel_get(all, hitx * 64 , j * 64 / wall ,i);
		else
			color = my_mlx_pixel_get(all, hity * 64 , j * 64 / wall ,i);
		my_mlx_pixel_put(all->win, x, y++, color);
		j++;
	}
	while (y < HEIGHT - 1)
		my_mlx_pixel_put(all->win, x, y++, GREEN);
	
}