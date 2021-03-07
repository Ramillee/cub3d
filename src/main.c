/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/07 19:35:34 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void fill_struct(t_win  *mlx_st)
{
	mlx_st->mlx = mlx_init();
	mlx_st->win = mlx_new_window(mlx_st->mlx,1920,1080,"Cub3D");
	mlx_st->img = mlx_new_image(mlx_st->mlx, 1920, 1080);
    mlx_st->addr = mlx_get_data_addr(mlx_st->img, &mlx_st->bpp, &mlx_st->line_l,
					mlx_st->en);
}

int main(int argc, char **argv)
{
	char **map;
	
	(void) argc;
	t_win  mlx_st;
	fill_struct(&mlx_st);
	
    my_mlx_pixel_put(&mlx_st, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx_st.mlx, mlx_st.win, mlx_st.img, 0, 0);
	if (parcer(argv[1], &map) == -1)
		printf("error");
	//----------------------------------------------------------------
	printf("%s\n",map[0]);
	printf("%s\n",map[1]);
	printf("%s\n",map[2]);
	//----------------------------------------------------------------
	
	mlx_loop(mlx_st.mlx );
	return (0);
}

