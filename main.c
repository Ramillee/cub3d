/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:13 by atweek            #+#    #+#             */
/*   Updated: 2021/02/03 21:03:18 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int     main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;

	x = 100;
	y = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	while (y ++ < 200)
	{
		x = 100;
		while (x ++ < 200)
			mlx_pixel_put(mlx,mlx_win,x,y,0x0000FF00);
	}
	mlx_loop(mlx);
	return (0);
}