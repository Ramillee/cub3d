/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/30 15:05:26 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int    my_mlx_pixel_get(t_all *all_st, int x, int y,int i)
{
	char    *dst;
	dst = all_st->textures[i]->addr + (y * all_st->textures[i]->line_l + x * (all_st->textures[i]->bpp / 8));
	return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void paint_square(t_win *data,float x, float y, int color)
{
	float start_x;
	float start_y;

	start_y = y;
	start_x = x;
	while (y++ < SCALE + start_y)
	{
		x = start_x;
		while (x++ < SCALE + start_x)
			my_mlx_pixel_put(data, x, y, color);
	}
}


void paint_line(t_all *all, t_ray *ray_st,int x)
{
	int y;
	double wall;
	double sky;
	double hitx;
	double hity;
	 int color;
	static int i; 

	hitx = (ray_st->ray_x / 32) - (int)(ray_st->ray_x / 32);
	hity = (ray_st->ray_y / 32)	 - (int)(ray_st->ray_y / 32);
	// printf("  :%d:  ",(int)ray_st->ray_x);
	// ray_st.ray_x
	
	// double j = (ray_st->ray_x - (int)ray_st->ray_x);
	// 	if (j < 0)
	// 		j *= -1;
	// ft_putnbr_fd(color,1);
	// ft_putchar_fd('\n',1);
	// printf("nomer lucha %d hx %f hy %f \n", x, hitx * 64, hity * 64);
	y = 0;
	// prop = (WIGHT / 2) / (tan(M_PI_2 / 3));
	// wall = (SCALE / len) * prop;
	wall = (HEIGHT / ray_st->ray_len) * 32;
	sky = HEIGHT / 2 - wall / 2;
	// printf("%f\n",sky);
	// int *i = [0,1,2,3];
	int j = 0;

	if (sky < 0)
		j += fabs(sky);
	else
		while (y < sky && y < HEIGHT - 1)
			my_mlx_pixel_put(all->win, x, y++, 0xFFFFFF);
	// j = y;
	while (y < wall + sky && y < HEIGHT - 1)
	{
		// my_mlx_pixel_put(all->win, x  , y++ , my_mlx_pixel_get(all, hitx * 64 ,j * 64 / wall ,2));
		if (((int)  ray_st->ray_x == (int) ray_st->old_x) && (int) ray_st->old_y - (int) ray_st->ray_y > 0)
			i = 0;
		else if (((int) ray_st->ray_x == (int) ray_st->old_x) && (int) ray_st->old_y - (int) ray_st->ray_y < 0)
			i = 1;
		else if (((int) ray_st->ray_y == (int) ray_st->old_y) && (int) ray_st->old_x - (int) ray_st->ray_x < 0)
			i = 2;
		else if (((int) ray_st->ray_y == (int) ray_st->old_y) && (int) ray_st->old_x - (int) ray_st->ray_x > 0)
			i = 3;
		// else
		// 	color = my_mlx_pixel_get(all, hitx * 64 ,j * 64 / wall ,1);
		if (i == 0 || i == 1)
			color = my_mlx_pixel_get(all, hitx * 64 , j * 64 / wall ,i);
		else
			color = my_mlx_pixel_get(all, hity * 64 , j * 64 / wall ,i);
		my_mlx_pixel_put(all->win, x, y++, color);
		j++;
	}
	while (y < HEIGHT - 1)
		my_mlx_pixel_put(all->win, x, y++, GREEN);
	
}

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

		// while (x < WIGHT)
			// paint_line(all,sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)),x++);
		// printf("%f\n",sqrt(pow(ray.x - all->plr->x,2) + pow(ray.y - all->plr->y,2)));
	}
	//
}

void fill_struct(t_win  *mlx_st,t_all *all_st)
{
	int i = -1;
	
	mlx_st->mlx = mlx_init();
	mlx_st->win = mlx_new_window(mlx_st->mlx,WIGHT,HEIGHT,"Cub3D");
	mlx_st->img = mlx_new_image(mlx_st->mlx, WIGHT, HEIGHT);
    mlx_st->addr = mlx_get_data_addr(mlx_st->img, &mlx_st->bpp, &mlx_st->line_l,
	&mlx_st->en);
	while (++i < 5)
	{
		all_st->textures[i]->img = mlx_xpm_file_to_image(mlx_st->mlx, all_st->textures[i]->linc,
		&all_st->textures[i]->weight, &all_st->textures[i]->height);
		all_st->textures[i]->addr = mlx_get_data_addr(all_st->textures[i]->img,
		&all_st->textures[i]->bpp, &all_st->textures[i]->line_l,
		&all_st->textures[i]->en);	
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

void find_player(t_plr *pl_st,float x ,float y)
{
	pl_st->x = x + (SCALE / 2);
	pl_st->y = y + (SCALE / 2);
	pl_st->dir = 0;
	pl_st->start = 0;
	pl_st->end = 0;
}

void  check_map(t_all *all_st)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (all_st->map[j])
	{
		while (all_st->map[j][i])
		{
			if ((all_st->map[j][i]  == 'N') || (all_st->map[j][i]  == 'S')
					 || (all_st->map[j][i]  == 'E') || (all_st->map[j][i]  == 'W'))
			{
				find_player(all_st->plr, i * SCALE , j * SCALE);//
				side_of_the_world(all_st->map[j][i], all_st);
			}
			i++;
		}
		j++;
		i = 0;
	}
	
}

// int paint_sprite(t_all *all_st)
// {
// 	int a;
// 	int count;

// 	a = -1;
// 	count = count_sprite(all_st);
// 	while (++a < count)
// 	{
// 		all_st->sprites[a].dir = atan2(all_st->sprites[a].y - all_st->plr->y, all_st->sprites[a].x - all_st->plr->x);
// 		all_st->sprites[a].dist = sqrt(pow(all_st->sprites[a].x - all_st->plr->x,2) + pow(all_st->sprites[a].y - all_st->plr->y,2));
// 		all_st->sprites[a].h_offset = (all_st->sprites[a].dir - player.a)*(fb.w/2)/(player.fov) + (fb.w/2)/2 - sprite_screen_size/2;
//     	all_st->sprites[a].v_offset = fb.h/2 - sprite_screen_size/2;
// 	}
	
// }

int close_window(t_all *all_st)
{
	//free
	while (all_st->map)
		free(all_st->map++);
	printf("1\n");
	exit(0);
	// return (0);
}


int		hook(int keycode, t_all *all)
{
	printf("%d\n",keycode);
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
		close_window(all);
	if (all->plr->dir > M_PI + M_PI)
		all->plr->dir = all->plr->dir - (M_PI + M_PI);
	ft_cast_rays(all);
	// pint_sprite(all);//-------------------------------
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_sync(all->win->mlx);
	return (0);
}

// //find_player
// int count_sprite(t_all *all_st)
// {
// 	int	i;
// 	int	j;
// 	int	count;
	
// 	count = 0;
// 	i = 0;
// 	j = 0;
// 	while (all_st->map[j])
// 	{
// 		while (all_st->map[j][i])
// 		{
// 			if (all_st->map[j][i]  == '2') 
// 			{
// 				count++;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	return (count);
// }

// // char *find_sprite(char sprites[i],i);


// void fill_sprite(t_all *all_st,int count)
// {
// 	int	j;
// 	t_sprite *sprites;
// 	int i;
// 	int a;
	
// 	sprites = (t_sprite *)malloc(sizeof(t_sprite) * count);
// 	all_st->sprites = sprites;
// 	i = 0;
// 	j = 0;
// 	a = 0;
// 	// all_st->sprites = malloc(sizeof(t_sprite) * count);
// 	while (all_st->map[j])
// 	{
// 		while (all_st->map[j][i])
// 		{
// 			if (all_st->map[j][i]  == '2') 
// 			{
// 				all_st->sprites[a].x = (float)i * SCALE;
// 				all_st->sprites[a].y =  (float)j * SCALE;
// 				all_st->sprites[a].dir =  0;
// 				// // printf("%d\n",count);
// 				printf("%f\n",all_st->sprites[a].x);
// 				printf("%f\n",all_st->sprites[a].y);
// 				// paint_square(all_st->win,all_st->sprites[a].x,all_st->sprites[a].y, 0xFF0000);
// 				a++;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	// while (++i < count)
// 	// {
		
// 	// }
// 	// pl_st->x = x + (SCALE / 2);
// 	// pl_st->y = y + (SCALE / 2);
// 	// pl_st->dir = 0;
// } 


int main(int argc, char **argv)
{	
	(void) argc;	
	(void) argv;//поменять
	t_win mlx_st;
	t_plr pl_st;
	t_all all_st;
	int i;
	
	i = 0;
	t_textures *texture;
	while (i < 5)
	{
		texture = malloc(sizeof(t_textures));
		all_st.textures[i] = texture;
		i++;
	}
	all_st.win = &mlx_st;
	all_st.plr = &pl_st;	
	all_st.textures[0]->linc = "./img/colorstone.xpm";//переместить в парсер
	all_st.textures[1]->linc = "./img/redbrick.xpm";
	all_st.textures[2]->linc = "./img/greystone.xpm";
	all_st.textures[3]->linc = "./img/wood.xpm";
	all_st.textures[4]->linc = "./img/pillar.xpm";
	fill_struct(&mlx_st,&all_st);//может быть тоже
	if ((all_st.map = parcer("./map/cub3d.cub")) == NULL)//поменять на argv
	{
		strerror(24);
		perror("");
		exit(0);
	}
	// all_st.map = map;
	// paint_map(&pl_st,&mlx_st,map, &all_st);
	check_map(&all_st);
	// printf("%d\n",count_sprite(&all_st));
	ft_cast_rays(&all_st);
	// fill_sprite(&all_st,count_sprite(&all_st));
	mlx_do_sync(all_st.win->mlx);
	mlx_put_image_to_window(all_st.win->mlx, all_st.win->win, all_st.win->img, 0, 0);
	// mlx_hook(all_st.win->win, 17, 0L, &close_window, &all_st);
	mlx_hook(all_st.win->win,  2, 1L<<0, &hook, &all_st);
	mlx_loop(all_st.win->mlx);
	return (0);
}
