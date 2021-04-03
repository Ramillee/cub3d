/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:19:22 by atweek            #+#    #+#             */
/*   Updated: 2021/04/03 11:20:24 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int close_window(t_all *all_st)
// {
// 	//free
// 	// while (all_st->map)
// 	// 	free(all_st->map++);
// 	// printf("end of the game\n");
// 	mlx_destroy_image(all_st->win->mlx,all_st->win->img);
// 	exit(0);
// 	return (0);
// }


int		hook(int keycode, t_all *all)
{
	// printf("%d\n",keycode);
	if (keycode == W && 
		(all->map[(int)((all->plr->y + STEP * sin(all->plr->dir)) / SCALE)]
		[(int) ((all->plr->x + STEP * cos(all->plr->dir)) /  SCALE)] != '1'))
	{
	all->plr->y += STEP * sin(all->plr->dir);
	all->plr->x += STEP * cos(all->plr->dir);
	}
	else if (keycode == S &&
	(all->map[(int)((all->plr->y - STEP * sin(all->plr->dir)) / SCALE)]
	[(int) ((all->plr->x - STEP * cos(all->plr->dir)) /  SCALE)] != '1'))
	{
			all->plr->y -= STEP * sin(all->plr->dir);
			all->plr->x -= STEP * cos(all->plr->dir);

	}
	else if (keycode == A &&
	(all->map[(int)((all->plr->y - STEP * cos(all->plr->dir)) / SCALE)]
	[(int) ((all->plr->x + STEP * sin(all->plr->dir)) /  SCALE)] != '1'))
	{
		all->plr->x += STEP * sin(all->plr->dir);
		all->plr->y -= STEP * cos(all->plr->dir);
	}
	else if (keycode == D && 
	(all->map[(int)((all->plr->y + STEP * cos(all->plr->dir)) / SCALE)]
	[(int) ((all->plr->x - STEP * sin(all->plr->dir)) /  SCALE)] != '1'))
	{
		all->plr->x -=  STEP * sin(all->plr->dir);
		all->plr->y += STEP * cos(all->plr->dir);
	}
	else if (keycode == LEFT)
		all->plr->dir -= 0.188;//maybe pla a
	else if (keycode == RIGHT)
		all->plr->dir  += 0.188;
	else if (keycode == ESC)
		free_all(all);
	if (all->plr->dir > M_PI + M_PI)
		all->plr->dir = all->plr->dir - (M_PI + M_PI);
	ft_cast_rays(all);
	// pint_sprite(all);//-------------------------------
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_sync(all->win->mlx);
	return (0);
}