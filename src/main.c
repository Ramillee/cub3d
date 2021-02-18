/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:13 by atweek            #+#    #+#             */
/*   Updated: 2021/02/18 20:17:42 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../gnl/get_next_line.h"
#include "cub.h"
#define SCALE 200

int		main(void)
{
	int fd;
	char *line;
	t_cub	st_cub;
	int x;
	int y;
	x = 10;
	y = 10;
	fd = open("map", O_RDONLY);
	
	st_cub.mlx = mlx_init();
	st_cub.mlx_win = mlx_new_window(st_cub.mlx, 1920, 1080, "Cub3d");
	while (get_next_line(fd,&line) == 1)
	{
		while (*line != '\n')
		{
			if (*line == '1')
			{
				write_square(x,y,&st_cub,0x00FF0000);
				x += SCALE;
			}
			if (*line == '0')
			{
				write_square(x,y,&st_cub,0x000000FF);
				x += SCALE;
			}
			if (*line == '\0')
			{
				y += SCALE;
			}
			line++;
		}
		line = NULL;
		free(line);
	}
	mlx_loop(st_cub.mlx);
}

int		write_square(int x, int y,t_cub *st_cub,int color)
{

	int x_save;

	x_save = x;
	printf("%d",1);
	while (y ++ < SCALE)
	{
		x = x_save;
		while (x ++ < SCALE)
			mlx_pixel_put(st_cub->mlx,st_cub->mlx_win,x,y,color);
	}
	return (0);
}

