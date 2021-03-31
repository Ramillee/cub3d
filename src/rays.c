/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:18:11 by atweek            #+#    #+#             */
/*   Updated: 2021/03/31 21:55:37 by atweek           ###   ########.fr       */
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

	t_ray ray_st;
	all->plr->ray = &ray_st;
	// (void ) side;

	x = 0;
	ray_st.ray_step = (M_PI/3) / WIGHT;
	
	t_plr	ray = *all->plr;
	float start = ray.dir - M_PI_2/3; // начало веера лучей
	float end = ray.dir + M_PI_2/3; // край веера лучей
	
  while (start <= end)
	{
		ray_st.ray_x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray_st.ray_y = all->plr->y;
		while (all->map[(int)(ray_st.ray_y / SCALE)][(int)(ray_st.ray_x / SCALE)] != '1')
		{
			// if (all->map[(int)(ray_st.ray_y / SCALE)][(int)(ray_st.ray_x / SCALE)] == '2')
			// {
			// 	my_mlx_pixel_put(all->win,ray_st.ray_x, ray_st.old_y,0xFF0000);
			// }
				
			ray_st.old_x = ray_st.ray_x;
			ray_st.old_y = ray_st.ray_y;
			ray_st.ray_x += cos(start) / 10;
			ray_st.ray_y += sin(start) / 10;
		}
		start += ray_st.ray_step;
		ray_st.ray_len = sqrt(pow(ray_st.ray_x - all->plr->x,2) + pow(ray_st.ray_y - all->plr->y,2)) * cos(ray.dir - start);
		paint_line(all,&ray_st,x++);
		fill_sprite(all,count_sprite(all));


		// while (x < WIGHT)
			// paint_line(all,sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)),x++);
		// printf("%f\n",sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)));
	}
	//
}