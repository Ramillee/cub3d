/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/19 00:10:08 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

int    my_mlx_pixel_get(t_info *info,t_all *all_st, int x, int y)
{
   char    *dst;
   dst = all_st->textures->no->addr + (y * all_st->textures->no->line_l + x * (all_st->textures->no->bpp / 8));
   return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void paint_line(t_all *all, long double len, int x, double rayx, double rayy)
{
	int y;
	long double wall;
	long double something;
	double hitx;
	double hity;
	int color = 0;

	hitx = rayx - (int)rayx;
	hity = rayy - (int)rayy;
	int j = 0;
	// ft_putnbr_fd(color,1);
	// ft_putchar_fd('\n',1);
	// printf("nomer lucha %d hx %f hy %f \n", x, hitx * 64, hity * 64);
	y = 0;
	// prop = (WIGHT / 2) / (tan(M_PI_2 / 3));
	// wall = (SCALE / len) * prop;
	wall = (WIGHT / len) * 30;
	something = HEIGHT / 2 - wall / 2;
	while (y < something && y < HEIGHT - 1)
		my_mlx_pixel_put(all->win, x, y++, BLUE);
	while (y < wall + something && y < HEIGHT - 1)
	{
		color = my_mlx_pixel_get(all->info,all, hitx * 64,j * 64 / wall);
		my_mlx_pixel_put(all->win, x, y++, color);
		j ++;
	}
	while (y < HEIGHT - 1)
		my_mlx_pixel_put(all->win, x, y++, GREEN);
	
}

void	ft_cast_rays(t_all *all)
{
	long double ray_step;
	long double x;
	long double ray_len;

	x = 0;
	ray_step = (M_PI / 3) / WIGHT;
	
	t_plr	ray = *all->plr;
	long double start = ray.dir - M_PI_2 / 3; // начало веера лучей
	long double end = ray.dir + M_PI_2 / 3; // край веера лучей
	
  while (start <= end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(start) / 10;
			ray.y += sin(start) / 10;
		}
		start += ray_step;
		ray_len = sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)) * cos(ray.dir - start);
		// 
		paint_line(all,ray_len,x++, ray.x / SCALE, ray.y / SCALE);

		// while (x < WIGHT)
			// paint_line(all,sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)),x++);
		// printf("%f\n",sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)));
	}
}

void fill_struct(t_win  *mlx_st, t_all *all_st)
{
	mlx_st->mlx = mlx_init();
	mlx_st->win = mlx_new_window(mlx_st->mlx,WIGHT,HEIGHT,"Cub3D");
	mlx_st->img = mlx_new_image(mlx_st->mlx, WIGHT, HEIGHT);
    mlx_st->addr = mlx_get_data_addr(mlx_st->img, &mlx_st->bpp, &mlx_st->line_l,
	&mlx_st->en);
	all_st->textures->no->img = mlx_xpm_file_to_image(mlx_st->mlx, all_st->textures->no->linc, &all_st->textures->no->weight, &all_st->textures->no->height);
	all_st->textures->no->addr = mlx_get_data_addr(all_st->textures->no->img, &all_st->textures->no->bpp, &all_st->textures->no->line_l,
	&all_st->textures->no->en);
//	ft_putnbr_fd(all_st->info->weight_no, 1);
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

void find_player(t_plr *pl_st,double x ,double y)
{
	pl_st->x = x + (SCALE / 2);
	pl_st->y = y + (SCALE / 2);
	//--------------
	// printf("%s%f\n","x: ",x);
	// printf("%s%f\n","y: ",y);
	//--------------
	pl_st->dir = 0;
	pl_st->start = 0;
	pl_st->end = 0;
	// paint_square(all_st->win, x, y, BLUE);
}

void  check_map(t_all *all_st)
{
	int y;
	int x;
	int i;
	int j;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	
	while (all_st->map[j])
	{
		x = 0;
		while (all_st->map[j][i])
		{
			if ((all_st->map[j][i]  == 'N') || (all_st->map[j][i]  == 'S')
					 || (all_st->map[j][i]  == 'E') || (all_st->map[j][i]  == 'W'))
			{
				find_player(all_st->plr, x , y);//
				side_of_the_world(all_st->map[j][i], all_st);
			}
			x += SCALE;
			i++;
		}
		y += SCALE;
		j++;
		i = 0;
	}
	
}

int		hook(int keycode, t_all *all_st)
{
	// printf("move\n");
	// printf("%d\n",keycode);
	if (keycode == W)
	{
		all_st->plr->y += STEP * sin(all_st->plr->dir);
		all_st->plr->x += STEP * cos(all_st->plr->dir);
	}
	else if (keycode == S )
	{
		all_st->plr->y -= STEP * sin(all_st->plr->dir);
		all_st->plr->x -= STEP * cos(all_st->plr->dir);
	}
	else if (keycode == A )
	{
		all_st->plr->x += STEP * sin(all_st->plr->dir);
		all_st->plr->y -= STEP * cos(all_st->plr->dir);
	}
	else if (keycode == D )
	{
		all_st->plr->x -=  STEP * sin(all_st->plr->dir);
		all_st->plr->y += STEP * cos(all_st->plr->dir);
	}
	else if (keycode == LEFT)
		all_st->plr->dir -= 0.188;
	else if (keycode == RIGHT)
		all_st->plr->dir  += 0.188;
	ft_cast_rays(all_st);
	// int	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, vall_st->win->img);
	mlx_put_image_to_window(all_st->win->mlx, all_st->win->win, all_st->win->img, 0, 0);
	// printf("%s%f\n","x = ", all_st->plr->x);
	// printf("%s%f\n","y = ", all_st->plr->y);
		// paint_square(all_st->win->mlx, all_st->plr->x + 1, all_st->plr->y + 1, BLUE);
	return (0);
}

int main(int argc, char **argv)
{
	char **map;
	
	(void) argc;
	(void) argv;//поменять
	t_win mlx_st;
	t_info info_st;
	t_plr pl_st;
	t_all all_st;
	t_no no;
	t_textures textures_st;
	all_st.textures = &textures;
	all_st.info = &info_st;
	all_st.win = &mlx_st;
	all_st.plr = &pl_st;
	all_st->textures = 
	// struct_texture(all_st,);
	// info_st.NO = "../img/colorstone.xpm";
	fill_struct(&mlx_st, &all_st);
	if (parcer("map", &map) == -1)//поменять
	{
		ft_putstr_fd("error",1);
		exit(0);
		// strerror(24)
		// perror("");
	}
	all_st.map = map;
	// paint_map(&pl_st,&mlx_st,map, &all_st);
	check_map(&all_st);
	ft_cast_rays(&all_st);
	mlx_put_image_to_window(mlx_st.mlx, mlx_st.win, mlx_st.img, 0, 0);
	// mlx_hook(mlx_st.win,  2, 1L<<0, hook, &all_st);
	// mlx_hook(&mlx_st,2 , (1L<<0));
	// //----------------------------------------------------------------
	// printf("%s\n",map[0]);  
	// printf("%s\n",map[1]);
	// printf("%s\n",map[2]);
	// //----------------------------------------------------------------
	mlx_hook(mlx_st.win,  2, 1L<<0, hook, &all_st);
	mlx_loop(mlx_st.mlx);
	return (0);
}
