#include "cub.h"

int	pixel_get(t_all *all_st, int x, int y, int i)
{
	char	*dst;

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

void	chec_side(t_all *all, t_painter *pnt, int j)
{
	static int	i;

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
		pnt->color = pixel_get(all, pnt->hitx * SCALE,
				j * SCALE / pnt->wall, i);
	else
		pnt->color = pixel_get(all, pnt->hity * SCALE,
				j * SCALE / pnt->wall, i);
}

void	paint_line(t_all *all, int x)
{
	t_painter	pnt;
	int			j;
	int			y;

	pnt.hitx = (all->plr->ray->x / SCALE) - (int)(all->plr->ray->x / SCALE);
	pnt.hity = (all->plr->ray->y / SCALE) - (int)(all->plr->ray->y / SCALE);
	y = 0;
	pnt.wall = (all->info->h / all->plr->ray->ray_len) * SCALE;
	pnt.sky = all->info->h / 2 - pnt.wall / 2;
	j = 0;
	if (pnt.sky < 0)
		j += fabs(pnt.sky);
	else
		while (y < pnt.sky && y < all->info->h - 1)
			my_mlx_pixel_put(all, x, y++, all->info->c);
	while (y < pnt.wall + pnt.sky && y < all->info->h - 1)
	{
		chec_side(all, &pnt, j);
		my_mlx_pixel_put(all, x, y++, pnt.color);
		j++;
	}
	while (y < all->info->h - 1)
		my_mlx_pixel_put(all, x, y++, all->info->f);
}
