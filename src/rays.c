/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:18:11 by atweek            #+#    #+#             */
/*   Updated: 2021/04/01 04:07:05 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_cast_rays(t_all *all)
{
	// long double ray_step;
	float x;
	// long double ray_len;
	// // int	side = 0;
	// int old_x = 0;
	// int old_y = 0;

	// // t_ray ray_st;
	// all->plr->ray = &ray_st;
	// (void ) side;

	x = 0;
	all->plr->ray->ray_step = (M_PI/3) / WIGHT;
	
	// t_plr	ray = *all->plr;
	float start = all->plr->dir - M_PI_2/3; // начало веера лучей
	float end = all->plr->dir + M_PI_2/3; // край веера лучей
	
  while (start <= end)
	{
		all->plr->ray-> x = all->plr->x; // каждый раз возвращаемся в точку начала
		all->plr->ray->y = all->plr->y;
		while (all->map[(int)(all->plr->ray->y / SCALE)][(int)(all->plr->ray->x / SCALE)] != '1')
		{
			// if (all->map[(int)(ray_st.ray_y / SCALE)][(int)(ray_st.ray_x / SCALE)] == '2')
			// {
			// 	my_mlx_pixel_put(all->win,ray_st.ray_x, ray_st.old_y,0xFF0000);
			// }
				
			all->plr->ray->old_x = all->plr->ray->x;
			all->plr->ray->old_y = all->plr->ray->y;
			all->plr->ray->x += cos(start) / 10;
			all->plr->ray->y += sin(start) / 10;
		}
		start += all->plr->ray->ray_step;
		all->plr->ray->ray_len = sqrt(pow(all->plr->ray->x - all->plr->x,2) + pow(all->plr->ray->y - all->plr->y,2)) * cos(all->plr->dir - start);
		paint_line(all,x++);
		// fill_sprite(all);
		math_sprite(all,all->count_sprite);


		// while (x < WIGHT)
			// paint_line(all,sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)),x++);
		// printf("%f\n",sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)));
	}
	//
}