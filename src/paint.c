/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:21:10 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 07:52:46 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pixel_get(t_all *all_st, int x, int y, int i)
{
	char	*dst;
	// printf("1\n");

	dst = all_st->text[i]->addr + (y * all_st->text[i]->line_l + x
			* (all_st->text[i]->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && y < all->info->h && x < all->info->w)
	{
		dst = all->win->addr + (y * all->win->line_l + x * (all->win->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	paint_line(t_all *all, int x)
{
	int			y;
	double		wall;
	double		sky;
	double		hitx;
	double		hity;
	int			color;
	static int	i;
	int			j;

	hitx = (all->plr->ray->x / SCALE) - (int)(all->plr->ray->x / SCALE);
	hity = (all->plr->ray->y / SCALE) - (int)(all->plr->ray->y / SCALE);
	y = 0;
	wall = (all->info->h / all->plr->ray->ray_len) * SCALE;
	sky = all->info->h / 2 - wall / 2;
	j = 0;
	if (sky < 0)
		j += fabs(sky);
	else
		while (y < sky && y < all->info->h - 1)
			my_mlx_pixel_put(all, x, y++, all->info->c);
	while (y < wall + sky && y < all->info->h - 1)
	{
		if (((int) all->plr->ray->x == (int) all->plr->ray->old_x)
			&& (int) all->plr->ray->old_y - (int) all->plr->ray->y > 0)
			i = 0;
		else if (((int) all->plr->ray->x == (int) all->plr->ray->old_x)
			&& (int) all->plr->ray->old_y - (int) all->plr->ray->y < 0)
			i = 1;
		else if (((int) all->plr->ray->y == (int) all->plr->ray->old_y)
			&& (int) all->plr->ray->old_x - (int) all->plr->ray->x < 0)
			i = 2;
		else if (((int) all->plr->ray->y == (int) all->plr->ray->old_y)
			&& (int) all->plr->ray->old_x - (int) all->plr->ray->x > 0)
			i = 3;
		if (i == 0 || i == 1)
			color = pixel_get(all, hitx * SCALE, j * SCALE / wall, i);
		else
			color = pixel_get(all, hity * SCALE, j * SCALE / wall, i);
		my_mlx_pixel_put(all, x, y++, color);
		j++;
	}
	while (y < all->info->h - 1)
		my_mlx_pixel_put(all, x, y++, all->info->f);
}
