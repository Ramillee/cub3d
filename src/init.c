/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:01:31 by atweek            #+#    #+#             */
/*   Updated: 2021/04/02 19:01:58 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_struct(t_all *all_st)
{
	int i;
	t_win		*win;
	t_plr		*pl_st;
	t_textures	*texture[5];
	t_ray		*ray_st;
	
	i = 0;
	if ((win = ft_calloc(1,sizeof(t_win))) == NULL)
		return (-1);
	all_st->win = win;
	if ((pl_st = ft_calloc(1,sizeof(t_plr))) == NULL)
		return (-1);
	all_st->plr = pl_st;
	if ((ray_st = ft_calloc(1,sizeof(t_ray))) == NULL)
		return (-1);
	all_st->plr->ray = ray_st;
	while (i < 5)
	{
		if ((texture[i] = ft_calloc(1,sizeof(t_textures))) == NULL)
			return(-1);
		all_st->textures[i] = texture[i];
		i++;
	}
	return (1);
}

int init_sprite(t_all *all_st,int count)
{
	int i;
	int j;
	int a;
	t_sprite *sprites;
	
	// count = count_sprite(all_st);
	i = 0;
	j = 0;
	a = 0;
	sprites = ((t_sprite *)ft_calloc(1,sizeof(t_sprite *) * count));
	all_st->sprites = sprites;
	while (all_st->map[j])
	{
		while (all_st->map[j][i])
		{
			if (all_st->map[j][i]  == '2') 
			{
				all_st->sprites[a].x = (float)i * SCALE;
				all_st->sprites[a].y =  (float)j * SCALE;
				all_st->sprites[a].dir =  0;
				// math_sprite(all_st,count);
				a++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}