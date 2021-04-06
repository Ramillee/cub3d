/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:37:59 by atweek            #+#    #+#             */
/*   Updated: 2021/04/06 02:59:50 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void sort(t_all *all)
{
// 	int i;
	// char *strs;
	// int max;
	int j;
	t_sprite tmp;
	
	j = 0;
	// max =  0;
		while (j < all->count_sprite - 1)
		{
			if (all->sprites[j].dist < all->sprites[j+1].dist)
			{
				tmp = all->sprites[j+1];
				all->sprites[j + 1] = all->sprites[j];
				all->sprites[j] = tmp;
				j = 0;
			}
			else
				j++;
		}
	// i = 0;
	// while (i < all->count_sprite)
	// 	printf("--- %f\n",all->sprites[i++].dist);
	// exit(0);
	// printf("")
	// paint_sprites(all_st,a);
}		
