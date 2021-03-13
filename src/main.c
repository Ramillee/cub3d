/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/13 22:43:52 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>
#define SCALE 32

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void paint_square(t_win *data,int x, int y, int color)
{
	int start_x;
	int start_y;

	start_y = y;
	start_x = x;
	while (y++ < SCALE + start_y)
	{
		x = start_x;
		while (x++ < SCALE + start_x)
			my_mlx_pixel_put(data, x, y, color);
	}
}

void find_player(t_plr *pl_st, t_all *all_st,float x ,float y)
{
	pl_st->x = x + (SCALE / 2);
	pl_st->y = y + (SCALE / 2);
	//--------------
	printf("%s%f\n","x: ",x);
	printf("%s%f\n","y: ",y);
	//--------------
	pl_st->dir = 0;
	pl_st->start = 0;
	pl_st->end = 0;
	paint_square(all_st->win, x, y, BLUE);
}

void next_paint_map(char **map, t_all *all_st)
{
	int y;
	int x;
	int i;
	int j;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		x = 0;
		while (map[j][i])
		{
			if (map[j][i]  == '1')
				paint_square(all_st->win, x, y, RED);
			else
				paint_square(all_st->win, x, y, GREEN);
			x += SCALE;
			i++;
		}
		y += SCALE;
		j++;
		i = 0;
	}
	
}

void side_of_the_world(char side, t_all *all_st)
{
	if (side == 'N')
		all_st->plr->dir = M_PI_2 * 3;
	if (side == 'E')
		all_st->plr->dir = 0;
	if (side == 'S')
		all_st->plr->dir = M_PI_2;
	if (side == 'W')
		all_st->plr->dir = M_PI;
}

void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr;

	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		my_mlx_pixel_put(all->win, ray.x, ray.y, 0x990099);
	}
}

void first_paint_map(t_plr *pl_st, t_win  *mlx_st, char **map, t_all *all_st)
{
	int y;
	int x;
	int i;
	int j;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		x = 0;
		while (map[j][i])
		{
			if (map[j][i]  == '1')
				paint_square(mlx_st, x, y, RED);
			else if ((map[j][i]  == 'N') || (map[j][i]  == 'S')
					 || (map[j][i]  == 'E') || (map[j][i]  == 'W'))
			{
				find_player(pl_st, all_st, x , y);
				side_of_the_world(map[j][i], all_st);
			}
			else
				paint_square(mlx_st, x, y, GREEN);
			x += SCALE;
			i++;
		}
		y += SCALE;
		j++;
		i = 0;
	}
	
}


void fill_struct(t_win  *mlx_st, t_all *all_st)
{
	mlx_st->mlx = mlx_init();
	mlx_st->win = mlx_new_window(mlx_st->mlx,1920,1080,"Cub3D");
	mlx_st->img = mlx_new_image(mlx_st->mlx, 1920, 1080);
    mlx_st->addr = mlx_get_data_addr(mlx_st->img, &mlx_st->bpp, &mlx_st->line_l,
	&mlx_st->en);
}

int		hook(int keycode, t_all *all_st)
{
	printf("move\n");
	printf("%d\n",keycode);
	if (keycode == W)
	{
		all_st->plr->y += STEP * sin(all_st->plr->dir);
		all_st->plr->x += STEP * cos(all_st->plr->dir);
	}
	else if (keycode == S)
	{
		all_st->plr->y -= STEP * sin(all_st->plr->dir);
		all_st->plr->x -= STEP * cos(all_st->plr->dir);
	}
	else if (keycode == A)
	{
		all_st->plr->x += STEP * cos(all_st->plr->dir);
		all_st->plr->y += STEP * sin(all_st->plr->dir);
	}
	else if (keycode == D)
	{
		all_st->plr->x -= STEP * cos(all_st->plr->dir);
		all_st->plr->y -= STEP * sin(all_st->plr->dir);
	}
	else if (keycode == LEFT)
		all_st->plr->dir -= 0.1;
	else if (keycode == RIGHT)
		all_st->plr->dir  += 0.1;
	next_paint_map(all_st->map, all_st);
	paint_square(all_st->win, all_st->plr->x - (SCALE / 2), all_st->plr->y - (SCALE / 2), BLUE);
	ft_cast_ray(all_st);
	mlx_put_image_to_window(all_st->win->mlx, all_st->win->win, all_st->win->img, 0, 0);
	printf("%s%f\n","x = ", all_st->plr->x);
	printf("%s%f\n","y = ", all_st->plr->y);
		// paint_square(all_st->win->mlx, all_st->plr->x + 1, all_st->plr->y + 1, BLUE);
}

int main(int argc, char **argv)
{
	char **map;
	
	(void) argc;
	t_win  mlx_st;
	t_plr pl_st;
	t_all all_st;
	all_st.win = &mlx_st;
	all_st.plr = &pl_st;
	fill_struct(&mlx_st, &all_st);
	
	if (parcer(argv[1], &map) == -1)
	{
		ft_putstr_fd("error",1);
		exit(0);
	}
	all_st.map = map;
	first_paint_map(&pl_st,&mlx_st,map, &all_st);

	
	mlx_put_image_to_window(mlx_st.mlx, mlx_st.win, mlx_st.img, 0, 0);
	mlx_hook(mlx_st.win,  2, 1L<<0, hook, &all_st);
	// mlx_hook(&mlx_st,2 , (1L<<0));
	// //----------------------------------------------------------------
	// printf("%s\n",map[0]);  
	// printf("%s\n",map[1]);
	// printf("%s\n",map[2]);
	// //----------------------------------------------------------------
	mlx_loop(mlx_st.mlx);
	return (0);
}
