/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:19:22 by atweek            #+#    #+#             */
/*   Updated: 2021/04/10 17:55:51 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	hook2(int keycode, t_all *all)
{
	if (keycode == D
		&& (all->map[(int)((all->plr->y + STEP * cos(all->plr->dir)) / SCALE)]
		[(int)((all->plr->x - STEP * sin(all->plr->dir)) / SCALE)] != '1'))
	{
		all->plr->x -= STEP * sin(all->plr->dir);
		all->plr->y += STEP * cos(all->plr->dir);
	}
	else if (keycode == LEFT)
		all->plr->dir -= 0.188;
	else if (keycode == RIGHT)
		all->plr->dir += 0.188;
	else if (keycode == ESC)
		free_all(all);
	if (all->plr->dir > M_PI + M_PI)
		all->plr->dir = all->plr->dir - (M_PI + M_PI);
	ft_cast_rays(all);
	mlx_do_sync(all->win->mlx);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}

int	hook(int keycode, t_all *all)
{
	if (keycode == W
		&& (all->map[(int)((all->plr->y + STEP * sin(all->plr->dir)) / SCALE)]
		[(int)((all->plr->x + STEP * cos(all->plr->dir)) / SCALE)] != '1'))
	{
		all->plr->y += STEP * sin(all->plr->dir);
		all->plr->x += STEP * cos(all->plr->dir);
	}
	else if (keycode == S
		&& (all->map[(int)((all->plr->y - STEP * sin(all->plr->dir)) / SCALE)]
		[(int)((all->plr->x - STEP * cos(all->plr->dir)) / SCALE)] != '1'))
	{
		all->plr->y -= STEP * sin(all->plr->dir);
		all->plr->x -= STEP * cos(all->plr->dir);
	}
	else if (keycode == A
		&& (all->map[(int)((all->plr->y - STEP * cos(all->plr->dir)) / SCALE)]
		[(int)((all->plr->x + STEP * sin(all->plr->dir)) / SCALE)] != '1'))
	{
		all->plr->x += STEP * sin(all->plr->dir);
		all->plr->y -= STEP * cos(all->plr->dir);
	}
	hook2(keycode, all);
	return (0);
}

static void	valid_check(t_all *all, int i, int j)
{
	if ((all->map[i][j] != ' ') && (all->map[i][j] != '1'))
	{
		if (((all->map[i][j + 1] == ' ') || (all->map[i][j + 1] == '\0'))
		|| (all->map[i][j - 1] == ' '))
			error(all, "error");
		if ((int)ft_strlen(all->map[i - 1]) <= j)
			error(all, "error");
		else if ((all->map[i - 1][j] == ' ')
			|| (all->map[i - 1][j] == '\0'))
			error(all, "error");
		if ((int)ft_strlen(all->map[i + 1]) <= j)
			error(all, "error");
		else if ((all->map[i + 1][j] == ' ')
			|| (all->map[i + 1][j] == '\0'))
			error(all, "error");
	}
}

void	valid_map(t_all *all)
{
	int	j;
	int	i;

	i = 0;
	while (all->map[i + 1])
	{
		j = 1;
		while (all->map[i][j] != '\0')
		{
			valid_check(all, i, j);
			j++;
		}
		i++;
	}
}
