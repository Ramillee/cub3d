/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:37:59 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 03:02:41 by atweek           ###   ########.fr       */
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
			if (all->sp[j].dist < all->sp[j+1].dist)
			{
				tmp = all->sp[j+1];
				all->sp[j + 1] = all->sp[j];
				all->sp[j] = tmp;
				j = 0;
			}
			else
				j++;
		}
	// i = 0;
	// while (i < all->count_sprite)
	// 	printf("--- %f\n",all->sp[i++].dist);
	// exit(0);
	// printf("")
	// paint_sp(all_st,a);
}		
