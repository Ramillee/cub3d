/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:25:36 by atweek            #+#    #+#             */
/*   Updated: 2021/03/26 21:29:42 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

check_s(t_all *all)
{
	int len;
	t_ray ray = all->plr->ray;
	
	while (all->map[(int)(ray.ray_y / SCALE)][(int)(ray.ray_x / SCALE)] != '1')
	{
		ray.ray_x += cos(all->plr->dir);
		ray.ray_y += sin(all->plr->dir);
	}
	len = sqrt(pow(ray.ray_x - all->plr->x,2) + pow(ray.ray_y - all->plr->y,2));
	if (len < STEP * 1.1)
		return (0);
	else
		return (1);
}