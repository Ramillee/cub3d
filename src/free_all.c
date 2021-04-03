/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:10:55 by atweek            #+#    #+#             */
/*   Updated: 2021/04/03 11:18:34 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_all(t_all *all)
{
    int i;
    int count;

    count = all->count_sprite;
    i = -1;
    // mlx_destroy_image(all->win->mlx,all->win->img);
    free(all->win);
    free(all->plr->ray);
    free(all->plr);
    while (++i < 5)
        free(all->textures[i]);
    i = -1;
    while (++i < count)
        free(all->sprites);
    free(all);
	exit(0);
}